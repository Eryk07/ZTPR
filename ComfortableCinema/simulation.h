#ifndef SIMULATION_H
#define SIMULATION_H

#include "settings.h"
#include "factors/factor.h"

class Simulation
{
public:
    Simulation();

    Settings* settings;
    Factor* factor;

};

#endif // SIMULATION_H
