#ifndef SCREENINGROOM_H
#define SCREENINGROOM_H

#include <vector>

#include "factors/conditions.h"
#include "simulation.h"

class ScreeningRoom
{
public:
    ScreeningRoom();
    int roomId;
    std::vector<Conditions> conditionsHistory;

    Conditions processSimulation();


private:
    Simulation* simulation;
    Conditions innerConditions;

};

#endif // SCREENINGROOM_H
