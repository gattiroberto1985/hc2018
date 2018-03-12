#include "../../inc/beans/position.h"
#include "../../inc/utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    println (" [ main ] creating position . . .");
    Position* pp = position_new( );
    println ( position_toString( pp ) );
    println (" [ main ] Setting new value for coordinates . . .");
    position_setX(pp, 19);
    position_setY(pp, 21);
    println ( position_toString( pp ) );
    println ( " [ main ] Destroying position . . .");
    position_destroy( pp );

    /*println ( " [ main ] Testing 2 param constructor . . .");
    pp = position_new( 13, 22);
    println ( "%s", position_toString( pp ) );

    position_destroy( pp );*/

    return 0;
}
