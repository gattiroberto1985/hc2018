#include "../../inc/beans/position.h"
#include "../../inc/utilities.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Position* position_new( ) {
    //printf(" [ position_new ] Entering position_new . . .\n");
    Position* pp = malloc ( sizeof ( Position ) );
    if ( pp == NULL ) {
        printf(" [ ride_new ] NULL ON malloc(Position)!\n");
    }
    //printf(" [ ride_new ] Setting X (on pointer %p) . . .\n", pp);
    position_setX(pp, 0);
    //printf(" [ ride_new ] Setting Y (on pointer %p) . . .\n", pp);
    position_setY(pp, 0);
    return pp;
}

/*Position* position_new(int x, int y) {
    Position* pp = position_new();
    position_setX(pp, x);
    position_setY(pp, y);
    return pp;
}*/

void position_destroy( Position* pp ) {
    if ( pp != NULL ) {
        printf( " [ position_destroy ] Destroying position@%p . . .\n", pp );
        //printf( " [ position_destroy ] Position to be destroyed: ");
        //position_toString(pp);
        free ( pp );
        pp = NULL;
    }
}

void position_setX(Position* pos, long newX) {
    //printf(" [ position_setX ] Setting x (actually at: %i). . .\n", pos->x);
    pos->x = newX;
}

void position_setY(Position* pos, long newY) {
    //printf(" [ position_setY ] Setting y (actually at: %i). . .\n", pos->y);
    pos->y = newY;
}

long position_getDistanceBetween(Position* p1, Position* p2) {
    return
        abs( p1->x - p2->x) + abs( p1->y - p2->y );
}

char* position_toString(Position* pos) {
    char* str;
    printf(" [ TEST ] [ position_toString ] Address of position is %p, with size: %i\n", pos, sizeof(pos));
    printf(" [ TEST ] [ position_toString ] X: %i (add. %p)\n", pos->x, &( pos->x ) );
    printf(" [ TEST ] [ position_toString ] Y: %i (add. %p)\n", pos->y, &( pos->y ) );
    sprintf( str, " { x: %i, y: %i }", pos->x, pos->y);
    return str;
}
