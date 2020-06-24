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

std::vector<Conditions> ScreeningRoom::getConditionsHistory() const
{
    return conditionsHistory;
}

void ScreeningRoom::setConditionsHistory(const std::vector<Conditions> &value)
{
    conditionsHistory = value;
}

void ScreeningRoom::clearConditionsHistory()
{
    conditionsHistory.clear();
}

QVector<double> ScreeningRoom::getTimestamps() const
{
    return timestamps;
}

void ScreeningRoom::setTimestamps(const QVector<double> &value)
{
    timestamps = value;
}

