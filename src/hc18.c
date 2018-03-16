#include "beans/game.h"
#include "beans/position.h"
#include "beans/ride.h"
#include "beans/car.h"
#include "utils/utilities.h"
#include "alg/planning.h"
#include "io/input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _DEBUG_print_list(Node* head) {
    printf(" [ main ] [ DEBUG ] Listing rides . . . \n");
    int i = 0;
    Node* node = head;
    while ( node  && node != NULL ) {
        printf(" [ main ] [ DEBUG ] El. %i is: ", i);
        node_toString(node);
        //printf(" [ main ] [ DEBUG ] node->next . . .\n");
        node = node->next;
        //printf( " [ main ] [ DEBUG ] i++ . . .\n");
        i++;
    }
}


int main(int argc, char const *argv[]) {

    //Let's start!

    //Reading user input
    char* iFile          = argv[0];
    long absMaxMarginVal = strtol(argv[1], &p, 10);

    // Defining some stuff . . .
    GameData* gameData = malloc( sizeof( GameData ) ) ;
    gameData->MAX_ABS_MARGIN = absMaxMarginVal;
    Node* ridesList = node_createList(0);
    // reading input file . . .
    char* iFile = "/cygdrive/c/Users/roberto.gatti/TEMP/HASHCODE_2018/my/input/a_example.in";//argv[0];
    char* oFile = "/cygdrive/c/Users/roberto.gatti/TEMP/HASHCODE_2018/my/output/a_example.out";//argv[0];
    // Reading input file, filling the ride list and the game data
    printf(" [ main ] About to read input file . . .\n");
    manage_input_file(iFile, ridesList, gameData);

    // // Debugging list . . .
    //_DEBUG_print_list(ridesList);

    // Planning rides and generating output file
    plan_rides(ridesList, gameData, oFile);
    //plan_ride_with_clone(ridesList, gameData, oFile);

    return 0;
}
