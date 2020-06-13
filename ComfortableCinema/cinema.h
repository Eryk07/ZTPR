#ifndef CINEMA_H
#define CINEMA_H

#include <vector>

#include "factors/conditions.h"
#include "screeningroom.h"

class Cinema
{
public:
    Cinema();

    void updateRooms();
    std::vector<Conditions> getRoomConditions(int roomId);


private:
    std::vector<ScreeningRoom> rooms;
};

#endif // CINEMA_H
