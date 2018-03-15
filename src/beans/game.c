#ifndef GAME_C
#define GAME_C

#include "game.h"
#include <stdio.h>

void game_toString(GameData* gd) {
    printf("---> GAMEDATA: { rows: %i, columns: %i, vehicleNum: %i, rideNum: %i, bonusForOnTimeLeave: %i, maxSimulationTime: %i }\n",
                gd->rows,
                gd->columns,
                gd->vehicleNum,
                gd->rideNum,
                gd->bonusForOnTimeLeave,
                gd->maxSimulationTime);
}


#endif
