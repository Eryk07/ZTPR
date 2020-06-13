#include "cinema.h"

Cinema::Cinema()
{

}

void Cinema::updateRooms()
{

}

std::vector<Conditions> Cinema::getRoomConditions(int roomId)
{
    std::vector<Conditions> roomConditions;
    Conditions momentCondition;
    for (int i=0; i<1001; i++)
    {
        momentCondition.CO2 += (i*0.3);
        momentCondition.humidity += (i*0.8);
        momentCondition.temperature += i;

        roomConditions.push_back(momentCondition);
    }

    return roomConditions;
}
