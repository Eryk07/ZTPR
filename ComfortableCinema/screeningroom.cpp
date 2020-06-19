#include "screeningroom.h"

ScreeningRoom::ScreeningRoom()
{
    this->simulation = new Simulation();

}

void ScreeningRoom::processSimulation()
{
//    Conditions momentCondition;
//    for (int i=0; i<1001; i++)
//    {
//        momentCondition.CO2 += (i*0.3);
//        momentCondition.humidity += (i*0.8);
//        momentCondition.temperature += i;

//        this->conditionsHistory.push_back(momentCondition);
//    }

    this->simulation->simulate(this->conditionsHistory, this->timestamps);

}

