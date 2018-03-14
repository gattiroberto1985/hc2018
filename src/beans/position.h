#ifndef POSITION
#define POSITION

#include "../utils/utilities.h"

typedef struct _Position {
    long x;
    long y;
} Position;

Position* position_new( );

// No override in C!
//Position* position_new(int x, int y);

void position_destroy( Position* pp);

void position_setX(Position* pos, long newX);

void position_setY(Position* pos, long newY);

char* position_toString(Position* pos);

long position_getDistanceBetween(Position* p1, Position* p2);

#endif
