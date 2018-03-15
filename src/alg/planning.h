#ifndef PLANNING_H
#define PLANNING_H
#include "../list/list.h"
#include "../beans/game.h"

void plan_rides(Node* ridesList, GameData* gameData, char* oFile);

void plan_rides_with_clone(Node* ridesList, GameData* gameData, char* oFile);

#endif
