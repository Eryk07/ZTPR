#ifndef CINEMA_H
#define CINEMA_H

#include <vector>

#include "factors/conditions.h"
#include "screeningroom.h"

/** Class of simulated cinema */
class Cinema
{
public:
    /** Constructor of Cinema class
    * @param *settings pointer to settings object from MainWindow class
    * */
    Cinema(Settings* settings);
    ~Cinema();
    /// Update conditions in rooms
    void updateRooms();
    /** Getter of vector of conditions in room
    * @param id of selected room
    * @return vector of room conditions
    */
    std::vector<Conditions> getRoomConditions(int roomId);
    /** Getter of vector of times of each conditions in room
    * @param id of selected room
    * @return vector of times of each conditions
    */
    QVector<double> getRoomSimTime(int roomId);


private:
    ///Vector of rooms in cinema
    std::vector<ScreeningRoom> rooms;
    /// Pointer to settings object from MainWindow class
    Settings* settings;
};

#endif // CINEMA_H
