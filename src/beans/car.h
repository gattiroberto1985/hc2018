#ifndef CAR_H
#define CAR_H
#include "../utils/utilities.h"
#include "position.h"

// Defining structure for Car object
typedef struct _Car {
    int       id;
    Position* position;  // current position of the car
//    long      totalTime; // total time of the rides run by the car
    long*     ridesRun;  // array with id of rides run
} Car;

Car* car_new();
void car_destroy(Car* pc);
void car_setId(Car* pc, int id);
void car_setPosition(Car* pc, Position* p);
void car_addRideRun(Car* pc, int rideId);
//void car_setTotalTime(Car* pc, long tt);

void car_toString(Car* pc);

#endif
