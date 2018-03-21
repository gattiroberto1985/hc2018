#ifndef CAR_C
#define CAR_C

#include "car.h"
#include "position.h"
#include "../utils/utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Car* car_new() {
    Car* pc = malloc( sizeof ( Car ) );
    if ( pc == NULL ) {
        // TODO: manage NULL!
    }
    car_setId(pc, 0);
    pc->position = position_new();
    //car_setPosition(pc, position_new());
    pc->ridesRun = NULL; //malloc( sizeof( long ) );
    //car_setTotalTime(pc, 0);
}

void car_destroy(Car* theCar) {
    //printf(" [ car_destroy ] Destroying car @%p . . . \n", theCar);
    position_destroy(theCar->position);
    free( theCar );
    //printf(" [ car_destroy ] Destroyed!\n");
}

void car_setId(Car* pc, int id) {
    pc->id = id;
}

void car_setPosition(Car* pc, Position* pp) {
    position_setX(pc->position, pp->x);
    position_setY(pc->position, pp->y);
}

void car_addRideRun(Car* pc, int rideId) {
    if ( pc->ridesRun == NULL ) {
        pc->ridesRun = malloc( sizeof( long ) );
    }

}
/*void car_setTotalTime(Car* pc, long tt) {
    pc->totalTime = tt;
}*/

void car_toString(Car* pc) {
    printf("{ id: %i, position: { x: %i, y: %i } }", pc->id, pc->position->x, pc->position->y);
}
#endif
