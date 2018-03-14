#include "ride.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Ride* ride_new( ) {
    Ride* pr = malloc( sizeof ( Ride ) );
    //printf(" [ ride_new ] Creating start position (via position_new) . . .\n");
    pr->start = position_new( );
    //printf(" [ ride_new ] Creating end position . . .\n");
    pr->end   = position_new( );
    //printf( " [ ride_new ] Defining default values . . .\n");
    //ride_setStart(pr, 0L);
    //ride_setEnd(pr, 0L);
    ride_setStartTime(pr, 0L);
    ride_setFinalTime(pr, 0L);
    ride_setId(pr, 0);
    ride_setHasRun(pr, FALSE);
    return pr;
}

void ride_destroy( Ride* r) {
    if ( r != NULL ) {
        printf( " [ ride_destroy ] Destroying ride . . .\n");
        printf( " [ ride_destroy ] Destroying start position . . .\n");
        position_destroy(r->start);
        position_destroy(r->end);
        free ( r );
        r = NULL;
    }
}

void ride_setStart(Ride* r, Position* ps) {
    //position_setX( &(r->start), ps->x);
    //position_setY( &(r->start), ps->y);
    r->start = ps;
}

void ride_setEnd(Ride* r, Position* pe) {
    //position_setX( &(r->end), pe->x);
    //position_setY( &(r->end), pe->y);
    r->end = pe;
}

void ride_setStartTime(Ride* r, long st) {
    r->startTime = st;
}

void ride_setFinalTime(Ride* r, long et) {
    r->finalTime = et;
}

void ride_setHasRun(Ride* r, bool hr) {
    r->hasRun = hr;
}

void ride_setId(Ride* r, int id) {
    r->id = id;
}

long ride_getMargin(Ride* r) {
    return -1;
}

long ride_calculateDistance( Ride* r ) {
    return position_getDistanceBetween( r->start, r->end );
}

void ride_toString(Ride* r) {
    //sprintf(rs, "{ id: %i, start: %s, end: %s, tStart: %i, tEnd: %i }", r->id, position_toString( &( r->start) ), position_toString( &( r->end) ), r->startTime, r->finalTime);
    printf( "Ride ---> { id: %i, tStart: %i, tEnd: %i, start: { x: %i, y: %i }, end: { x: %i, y: %i } }\n", r->id, r->startTime, r->finalTime, r->start->x, r->start->y, r->end->x, r->end->y);
    //printf(" [ ride_toString ] Printing positions: \n");
    //printf(" [ ride_toString ] r->start: %p\n", r->start);
    //printf(" [ ride_toString ] r->start: %p\n", & ( r->start) );
    ////printf( " [ ride_toString ] Start: %s\n", position_toString( r->start ));
    //char* ps;
    //strcpy( ps, position_toString( & ( r->start ) ) );
    //printf(" [ ride_toString ] Start (withps): %s", ps);
    //printf( " [ ride_toString ] Start: %s\n", position_toString( &( r->start) ));
    //printf( " [ ride_toString ] End  : %s\n", position_toString( &( r->end) ));
}
