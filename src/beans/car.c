#include "car.h"
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
    car_setPosition(pc, position_new());
    car_setTotalTime(pc, 0);
}

void car_setId(Car* pc, int id) {
    pc->id = id;
}

void car_setPosition(Car* pc, Position* pp) {
    pc->position = pp;
}

void car_setTotalTime(Car* pc, long tt) {
    pc->totalTime = tt;
}
