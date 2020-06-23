#include "screeningroom.h"

ScreeningRoom::ScreeningRoom(Settings* settings)
{
    this->settings = settings;
    this->simulation = new Simulation(settings);

}

void ScreeningRoom::processSimulation()
{
    this->simulation->simulate(this->conditionsHistory, this->timestamps);
}

