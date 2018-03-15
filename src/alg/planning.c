#ifndef PLANNING_C
#define PLANNING_C

#include "../utils/utilities.h"
#include "../beans/position.h"
#include "../beans/car.h"
#include "../beans/ride.h"
#include "../list/list.h"
#include "planning.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
- pianificazione corse:
*
*      per ogni macchina cerco la corsa con minimizzazione tra:
*        - distanza macchina - p_start_corsa (abs( p_in_corsa - p_in_macchina)) < parametro_interno_o_specificato
*        - t_start_corsa e valore di cui sopra ( deve essere > 0 )
*
*      se la corsa esiste, la assegno e procedo ad una nuova ricerca per la
*      stessa macchina, con nuove posizioni e tutto.
*/

void plan_rides(Node* ridesList, GameData* gameData, char* oFile) {
    printf(" [ plan_rides ] Planning rides . . .\n");

    for ( int carNo = 1; carNo <= gameData->vehicleNum; carNo++ ) {
        // Creating car, with start position (0, 0) (default value for position)
        Car* theCar = car_new( );
        car_setId( theCar, carNo );
        long residualTime = gameData->maxSimulationTime;
        //long currentTime  = 0;
        bool finishedSimulationForCar = FALSE;
        //printf( " [ plan_rides ] --> CAR %i is going to run rides: ", theCar->id );
        while ( finishedSimulationForCar != TRUE )
        {
            // Looping through list searching for the best matching ride
            Node* node = ridesList;
            Ride* theRide = NULL;
            long bestMargin = 1E10;
            long bestRideTotalTime = 1;
            long currentTime = gameData->maxSimulationTime - residualTime;
            printf( " [ plan_rides ] [ car no. %i] Starting ride loop . . .\n", theCar->id );
            while ( node != NULL ) {
                Ride* aRide = node->ride;
                printf( " [ plan_rides ] [ car no. %i] [ ride no. %i ] Check if run . . .\n", theCar->id, aRide->id );
                // Skip this ride if already run
                if ( aRide->hasRun == TRUE ) {
                    printf( " [ plan_rides ] [ car no. %i] [ ride no. %i ] |--> Already run! Skipping . . .\n", theCar->id, aRide->id );
                    node = node->next;
                    continue;
                }
                // Calculating the distance between the actual position of the car and the ride starting point
                long carDistanceFromStartRidePoint = position_getDistanceBetween(theCar->position, aRide->start);
                // Calculating the ride length
                long rideLength                    = ride_calculateDistance(aRide);
                // Calculating the margin (pause time [if ride can start on time] or late [if not]). Best values are
                // the smallest non-negative ones
                long margin = aRide->startTime - ( currentTime + carDistanceFromStartRidePoint );
                // Total ride time is the time :
                //   - for the car to get to the ride start position
                //   - for the ride to be run (i. e. the ride length)
                //   - the pause time, if >0 (the late must not be subtracted, but neither added!)
                long totalTime                     = carDistanceFromStartRidePoint + rideLength + ( margin >= 0 ? margin : 0);
                printf(" [ plan_rides ] [ car no. %i] [ ride no. %i ] ", theCar->id, aRide->id);
                ride_toString(aRide);
                car_toString(theCar);
                printf( "distance car-start ride point: %i ; length: %i ; margin: %i. Total time: %i\n",
                                carDistanceFromStartRidePoint,
                                rideLength,
                                margin,
                                totalTime);
                // So, let's check the conditions
                if (
                        margin >= 0                  && // Margin is non negative, i. e. the ride can start on time
                        margin < bestMargin          && // Margin is a better (i. e. lower) value than the current best margin
                        residualTime - totalTime > 0    // The ride will finish before the end of simulation
                    ) {
                    bestMargin = margin;
                    theRide = aRide;
                    bestRideTotalTime = totalTime;
                }

                // then pass to the next ride
                printf(" [ plan_rides ] [ car no. %i] [ ride no. %i ] |--> Checking next ride . . .\n", theCar->id, aRide->id);
                node = node->next;
            }
            // Checked all the rides. If theRide == NULL we have no ride to
            // manage, and then we can pass to the next car (if present)
            if ( theRide == NULL ) {
                printf(" [ plan_rides ] [ car no. %i] No ride fitting the conditions :( ! Passing to next car (if exists)!\n", theCar->id);
                finishedSimulationForCar = TRUE;
                continue;
            }

            // ... otherwise, we have a ride fitting all of our conditions!
            // Let's run it!
            printf(" [ plan_rides ] [ car no. %i] A ride has been found!\n", theCar->id);
            // Updating the residual simulation time
            residualTime = residualTime - bestRideTotalTime;
            // Updating the car position
            car_setPosition(theCar, theRide->end);
            // Setting the ride as run
            printf(" [ plan_rides ] [ car no. %i] Setting ride as run . . .\n", theCar->id);
            theRide->hasRun = TRUE;
            //printf("[ plan_rides ] [ car no. %i] ", theRide->id);
        }
        printf(" [ plan_rides ] [ car no. %i] Finished simulation for car. Passing to next on (if exists) . . . \n", theCar->id);
        printf("\n");
    }
}

void plan_rides_with_clone(Node* ridesList, GameData* gameData, char* oFile) {

}

#endif
