#ifndef RIDE
#define RIDE

#include "../utils/utilities.h"
#include "position.h"

typedef struct _Ride {
  Position* start;
  Position* end;
  long startTime;
  long finalTime;
  bool hasRun;
  int id;
} Ride;

Ride* ride_new              ( );
void ride_destroy           (Ride* r);
void ride_setStart          (Ride* r, Position* ps);
void ride_setEnd            (Ride* r, Position* pe);
void ride_setStartTime      (Ride* r, long st);
void ride_setFinalTime      (Ride* r, long et);
void ride_setHasRun         (Ride* r, bool hr);
void ride_setId             (Ride* r, int id);

long ride_getMargin         (Ride* r);

long ride_calculateDistance (Ride* r);

void ride_toString( Ride* r);

#endif
