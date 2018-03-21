/**
 * Planning algorythm ride-based. For every car we check if a ride which certain
 * conditions exists, and in such case we "run" this ride.
 *
 * The fitting conditions are:
 *
 *  - starting the ride within a certain "margin". By "margin" we mean this
 *    quantity:
 *
 *         start time of the ride - ( time for the car to get to ride initial position + current time )
 *
 *    If the margin is positive, then the ride will start on time but after a
 *    "pause period" of the car in the starting position. Here, the car is
 *    waiting the correct start time, as a ride CANNOT start before that moment.
 *    Otherwise, it represents a delay of the start time of the ride. In this
 *    case, the bonus points have gone. Pity!
 *
 *  - finishing the ride before the end of simulation, i. e.:
 *
 *         currentTime +
 *         time for the car to get to the ride initial position +
 *         time for the ride to be run +
 *         margin (only if positive as in this case it's time spent by the car waiting)
 *
 *    must be smaller than the total simulation time.
 *
 */
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

void plan_rides(Node* ridesList, GameData* gameData, char* oFile) {
    printf(" [ plan_rides ] Planning rides . . .\n");
    FILE* of = fopen(oFile, "w");
    if ( of == NULL )
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int totalRideManaged = 0;
    int totalRideOnTime = 0;

    for ( int carNo = 1; carNo <= gameData->vehicleNum; carNo++ ) {
        // Creating car, with start position (0, 0) (default value for position)
        printf(" [ plan_rides ] Analyzing car %i . . . \n", carNo);
        Car* theCar = car_new( );
        car_setId( theCar, carNo );
        fprintf(of, "Car: %i\tRides: ", theCar->id);
        long residualTime = gameData->maxSimulationTime;
        //long currentTime  = 0;
        bool finishedSimulationForCar = FALSE;
        int totalRidesOfCar = 0;
        int totalRidesLeavingOnTimeForCar = 0;
        //printf( " [ plan_rides ] --> CAR %i is going to run rides: ", theCar->id );
        while ( finishedSimulationForCar != TRUE )
        {
            // Looping through list searching for the best matching ride
            Node* node = ridesList;
            Ride* theRide = NULL;
            long bestAbsMargin = 1E10;
            long bestMargin = 1E10;
            long bestRideTotalTime = 1;
            long currentTime = gameData->maxSimulationTime - residualTime;
            //printf( " [ plan_rides ] [ car no. %i] Starting ride loop . . .\n", theCar->id );
            while ( node != NULL ) {
                Ride* aRide = node->ride;
                //printf( " [ plan_rides ] [ car no. %i] [ ride no. %i ] Check if run . . .\n", theCar->id, aRide->id );
                // Skip this ride if already run
                if ( aRide->hasRun == TRUE ) {
                    //printf( " [ plan_rides ] [ car no. %i] [ ride no. %i ] |--> Already run! Skipping . . .\n", theCar->id, aRide->id );
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
                //printf(" [ plan_rides ] [ car no. %i] [ ride no. %i ] ", theCar->id, aRide->id);
                //ride_toString(aRide);
                //car_toString(theCar);
                //printf( "distance car-start ride point: %i ; length: %i ; margin: %i. Total time: %i\n",
                //                carDistanceFromStartRidePoint,
                //                rideLength,
                //                margin,
                //                totalTime);
                // So, let's check the conditions
                if (
                        //margin >= 0                 && // Margin is non negative, i. e. the ride can start on time
                        abs( margin ) <= gameData->maxAbsMargin && // Margin is non negative, i. e. the ride can start on time
                        abs( margin ) < bestAbsMargin           && // Margin is a better (i. e. lower) value than the current best margin
                        residualTime - totalTime > 0               // The ride will finish before the end of simulation
                    ) {
                    bestAbsMargin = abs ( margin );
                    bestMargin = margin;
                    theRide = aRide;
                    bestRideTotalTime = totalTime;
                }

                // then pass to the next ride
                //printf(" [ plan_rides ] [ car no. %i] [ ride no. %i ] |--> Checking next ride . . .\n", theCar->id, aRide->id);
                node = node->next;
            }
            // Checked all the rides. If theRide == NULL we have no ride to
            // manage, and then we can pass to the next car (if present)
            if ( theRide == NULL ) {
                //printf(" [ plan_rides ] [ car no. %i] No ride fitting the conditions :( ! Passing to next car (if exists)!\n", theCar->id);
                finishedSimulationForCar = TRUE;
                continue;
            }

            // ... otherwise, we have a ride fitting all of our conditions!
            // Let's run it!
            //printf(" [ plan_rides ] [ car no. %i] A ride has been found (id: %i)!\n", theCar->id, theRide->id);
            // Updating the residual simulation time
            residualTime = residualTime - bestRideTotalTime;
            // Updating the car position
            car_setPosition(theCar, theRide->end);
            // Setting the ride as run
            //printf(" [ plan_rides ] [ car no. %i] [ ride no. %i] Setting ride as run . . .\n", theCar->id, theRide->id);
            theRide->hasRun = TRUE;
            totalRidesOfCar++;
            if ( bestMargin >= 0 )
                totalRidesLeavingOnTimeForCar++;
            fprintf(of, "%i ", theRide->id);
        }
        //printf(" [ plan_rides ] [ car no. %i] Finished simulation for car. Destroying it . . . \n", theCar->id);
        fprintf(of, " ( total rides managed: %i)\n", totalRidesOfCar);
        car_destroy(theCar);
        totalRideManaged += totalRidesOfCar;
        totalRideOnTime  += totalRidesLeavingOnTimeForCar;
    }
    printf (           "We have %i rides managed, %i of which started in time (margin >= 0)\n", totalRideManaged, totalRideOnTime);
    fprintf(of, "\n***\nWe have %i rides managed, %i of which started in time (margin >= 0)\n", totalRideManaged, totalRideOnTime);
    fclose(of);
}

void plan_rides_with_clone(Node* ridesList, GameData* gameData, char* oFile) {

}

#endif
