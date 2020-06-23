#ifndef SCREENINGROOM_H
#define SCREENINGROOM_H

#include <vector>

#include "factors/conditions.h"
#include "simulation.h"

class ScreeningRoom
{
public:
    ScreeningRoom(Settings* settings);
    std::vector<Conditions> conditionsHistory;
    QVector<double> timestamps;

    void processSimulation();


private:
    Simulation* simulation;
    Conditions innerConditions;
    Settings* settings;
};

#endif // SCREENINGROOM_H
