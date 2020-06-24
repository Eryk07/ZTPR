#include "cinema.h"

Cinema::Cinema(Settings* settings)
{
    this->settings = settings;

    for(int i=0; i<this->settings->getRoomsCount(); i++)
    {
        rooms.push_back(ScreeningRoom(settings));
    }
}

Cinema::~Cinema()
{
    rooms.clear();
}

void Cinema::updateRooms()
{
    for(unsigned int i=0; i<rooms.size(); i++)
    {
        if(!rooms[i].getConditionsHistory().empty())
            rooms[i].clearConditionsHistory();
        rooms[i].processSimulation();
    }
}

std::vector<Conditions> Cinema::getRoomConditions(int roomId)
{
    return rooms[roomId].getConditionsHistory();
}

QVector<double> Cinema::getRoomSimTime(int roomId)
{
    return rooms[roomId].getTimestamps();
}
