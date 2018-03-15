#ifndef INPUT_C
#define INPUT_C

#include "../list/list.h"
#include "../beans/game.h"
#include "../beans/position.h"
#include "../beans/car.h"
#include "../beans/ride.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void manage_input_file(const char* filePath, Node* rides, GameData* gameData) {

    FILE * fp;
    char line[100];
    size_t len = 0;
    ssize_t read;
    Node* node = rides;
    fp = fopen(filePath, "r");
    int count = 0;
    if (fp == NULL) {
        printf(" ***** ERROR: failure on opening file!\n");
        exit(EXIT_FAILURE);
    }

    printf(" [ manage_input_file ] About to start reading . . . \n");
    //while ((read = getline(&line, &len, fp)) != -1) {
    //while ((read = fgets(&line, &len, fp)) != -1) {
    /*printf(" ---------------------------------------------- \n");
    while (fgets(line, 100, fp) != NULL)
            printf("%s", line);
    printf(" ---------------------------------------------- \n");*/

    //printf( "%s\n", line);

    while ( fgets( line, 100, fp ) != NULL ) {
        /*int len = strlen(line);
        printf(" [ manage_input_file ] [ line no. %i ] --> entered (length: %i)", count, len );
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';*/
		//printf(" [ manage_input_file ] %s\n",line);
        printf( " [ manage_input_file ] [ line no. %i ] --> Read line: %s", count, line);
        //printf("line: %s\n", line);
        if ( count == 0 ) {
            printf( " [ manage_input_file ] [ line no. %i ] --> Reading gamedata . . . \n", count);
            /*printf(" -------------------- \n");
            printf( "%s\n", line);
            printf( "'%s'\n", line);
            printf(" -------------------- \n");*/
            //int r = 0, c = 0, v = 0, d = 0, b = 0, t = 0;
            //sscanf(line, "%i %i %i %i %i %i", &r, &c, &v, &d, &b, &t);
            //printf( "Registered game data: rows: %i, columns: %i, number of vehicles: %i, number of rides: %i, bonus: %i, total time: %i\n", r, c, v, d, b, t);
            sscanf(line, "%i %i %i %i %i %i", &(gameData->rows),
                                              &(gameData->columns),
                                              &(gameData->vehicleNum),
                                              &(gameData->rideNum),
                                              &(gameData->bonusForOnTimeLeave),
                                              &(gameData->maxSimulationTime));
            printf( " [ manage_input_file ] [ line no. %i ] ----> Registered game data: rows: %i, columns: %i, number of vehicles: %i, number of rides: %i, bonus: %i, total time: %i\n", count, gameData->rows, gameData->columns, gameData->vehicleNum, gameData->rideNum, gameData->bonusForOnTimeLeave, gameData->maxSimulationTime);
        }
        else {
            // abominious hack...
            if ( count > 1 ) {
                node->next = malloc( sizeof( Node ) ) ;
                node = node->next;
            }
            printf( " [ manage_input_file ] [ line no. %i ] --> Reading ride . . . \n", count);
            //printf("Reading ride . . .\n");
            //int sx = 0, sy = 0, ex = 0, ey = 0, ts = 0, te = 0;
            // Defining a new ride with the data . . .
            printf( " [ manage_input_file ] [ line no. %i ] ----> Allocating ride and positions . . . \n", count);
            Ride*     ride  = ride_new();     //malloc( sizeof ( Ride    ) ) ;
            Position* start = position_new(); //malloc( sizeof( Position ) );
            Position* end   = position_new(); //malloc( sizeof( Position ) );
            printf( " [ manage_input_file ] [ line no. %i ] ----> Setting ride start and end . . . \n", count);
            ride->id = count;
            ride->start = start;
            ride->end   = end;
            printf( " [ manage_input_file ] [ line no. %i ] ----> Getting data . . . \n", count);
            sscanf(line, "%i %i %i %i %i %i", &(ride->start->x),
                                              &(ride->start->y),
                                              &(ride->end->x),
                                              &(ride->end->y),
                                              &(ride->startTime),
                                              &(ride->finalTime));
            //printf(" --> Ride %i: [ %i, %i] to [ %i, %i] leave max on %i and arrive on %i\n", count, ride->start.x, ride->start.y, ride->end.x, ride->end.y, ride->startTime, ride->finalTime);
            // "node" is the previous element: defining the next element and setting the next->ride to the actual ride
            printf( " [ manage_input_file ] [ line no. %i ] ----> Setting ride node: ", count);
            node->ride = ride;
            node->next = NULL;
            node_toString(node);
        }
        count++;
    }
    //printf( " ------> last node: %p", node->next);
    fclose(fp);
    /*if (line)
      free(line);*/
    //exit(EXIT_SUCCESS);
}

#endif
