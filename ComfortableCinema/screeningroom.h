#ifndef SCREENINGROOM_H
#define SCREENINGROOM_H

#include <vector>

#include "factors/conditions.h"
#include "simulation.h"

/** Class of screening room of the cinema*/
class ScreeningRoom
{
public:
    /** Constructor of Screening Room class
    * @param *settings pointer to settings object from MainWindow class
    * */
    ScreeningRoom(Settings* settings);
    /// Function for processing simulation in room
    void processSimulation();

    std::vector<Conditions> getConditionsHistory() const;
    void setConditionsHistory(const std::vector<Conditions> &value);
    /// Clear history of room conditions
    void clearConditionsHistory();

    QVector<double> getTimestamps() const;
    void setTimestamps(const QVector<double> &value);

private:
    /// Pointer to simulation of conditions in room
    Simulation* simulation;
    /// Current conditions in room
    Conditions innerConditions;
    /// Pointer to settings object from MainWindow class
    Settings* settings;
    /// Vector of past room conditions
    std::vector<Conditions> conditionsHistory;
    /// Vector of times of each past room conditions
    QVector<double> timestamps;
};

#endif // SCREENINGROOM_H
