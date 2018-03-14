#ifndef UTILITIES
#define UTILITIES


#define FALSE 1
#define TRUE  0
#include <string.h>
#include <stdio.h>

// Defining boolean type (as alias of int :) )
typedef int bool;


// Defining structure for GameData object
typedef struct GameData {
    int rows;
    int columns;
    int vehicleNum;
    int rideNum;
    int bonusForOnTimeLeave;
    int maxSimulationTime;
} gamedata_t;

// Function to print and make new line
void println(char* str);

#endif
