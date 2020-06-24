#ifndef SCREENINGROOM_H
#define SCREENINGROOM_H

#include <vector>

#include "factors/conditions.h"
#include "simulation.h"

class ScreeningRoom
{
public:
    ScreeningRoom(Settings* settings);
    void processSimulation();

    std::vector<Conditions> getConditionsHistory() const;
    void setConditionsHistory(const std::vector<Conditions> &value);
    void clearConditionsHistory();

    QVector<double> getTimestamps() const;
    void setTimestamps(const QVector<double> &value);

private:
    Simulation* simulation;
    Conditions innerConditions;
    Settings* settings;
    std::vector<Conditions> conditionsHistory;
    QVector<double> timestamps;
};

#endif // SCREENINGROOM_H
