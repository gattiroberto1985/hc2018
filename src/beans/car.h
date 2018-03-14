#ifndef CAR_H
#define CAR_H
#include "../utils/utilities.h"
#include "position.h"

// Defining structure for Car object
typedef struct _Car {
    int       id;
    Position* position;  // current position of the car
    long      totalTime; // total time of the rides run by the car
} Car;

Car* car_new();
void car_setId(Car* pc, int id);
void car_setPosition(Car* pc, Position* p);
void car_setTotalTime(Car* pc, long tt);

#endif