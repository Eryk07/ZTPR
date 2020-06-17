#include "cinema.h"

Cinema::Cinema()
{
    int roomsCount= 1;  // docelowo to będzie zdefiniowane settings

    for(int i=0; i<roomsCount; i++)
    {
        rooms.push_back(ScreeningRoom());
    }
}

Cinema::~Cinema()
{
    rooms.clear();
}

void Cinema::updateRooms()
{
    for(unsigned int i=0; i<rooms.size(); i++)
        if(rooms[i].conditionsHistory.empty())
            rooms[i].processSimulation();

}

std::vector<Conditions> Cinema::getRoomConditions(int roomId)
{
    return rooms[roomId].conditionsHistory;
}
