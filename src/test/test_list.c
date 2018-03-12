#include "../../inc/list/list.h"
#include "../../inc/beans/ride.h"
#include "../../inc/utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {
    int listSize = 10;
    printf( " [ test_list ] Creating list with %i elements . . .\n", listSize);
    Node* theList = node_createList( 10 );
    printf( " [ test_list ] List size: %i\n", node_listLength( theList ) );

    for ( int i = 0; i < listSize; i++ ) {
        Ride* pr = ride_new( );
        //printf(" [ test_list ] Start of ride: { x: %i, y: %i }\n", pr->start.x, pr->start.y);
        printf( " [ test_list ] [ el. %i ] Printing element . . .\n", i);
        //ride_toString( pr );
        printf( " [ test_list ] [ el. %i ] Updating ride with some values . . .\n", i);
        // Start position
        Position* ps = position_new();
        position_setX(ps, 2*i*i);
        position_setY(ps, ( 2*i*i ) - 1);
        ride_setStart(pr, ps);
        // End position
        Position* pe = position_new();
        //position_destroy(pe);
        //pe = position_new();
        position_setX(pe, 2*i);
        position_setY(pe, ( 2*i ) - 1);
        ride_setEnd(pr, pe);
        //position_setX(pe, 2*i);
        //position_setY(pe, ( 2*i ) - 1);
        //ride_setEnd(pr, pe);
        //position_destroy(&(pr->start));
        //position_destroy(&(pr->end));
        //return 0;
        ride_setId(pr, i);
        ride_setStartTime(pr, i + 3);
        ride_setFinalTime(pr, i + 5);
        printf(" [ test_list ] [ el. %i ] Ride is: ", i);
        ride_toString( pr );
        printf( " [ test_list ] [ el. %i ] Updating element in list . . .\n", i);
        node_setElementInPos(theList, pr, i);
    }

    printf(" [ test_list ] ********************************************* \n");
    printf(" [ test_list ]               LISTING ELEMENTS                \n");
    printf(" [ test_list ] ********************************************* \n");
    printf(" [ test_list ] Printing the elements . . .\n");
    for ( int i = 0; i < listSize; i++ ) {
        Ride* pr = (Ride*) node_getElementAtPos(theList, i);
        printf(" [ test_list ] El @%i: ", i);
        ride_toString( pr );
    }

    //return 0;
    printf(" [ test_list ] Freeing up memory . . .\n");
    node_destroyList( theList );
    return 0;
}
