#ifndef GAME_H
#define GAME_H

typedef struct _GameData {
    int rows;
    int columns;
    int vehicleNum;
    int rideNum;
    int bonusForOnTimeLeave;
    int maxSimulationTime;
} GameData;

void game_toString(GameData* gd);

#endif
