#include "fan.h"

Fan::Fan(double speed)
{
    this->speed = speed;
}

void Fan::changeSpeed(double newSpeed)
{
    this->speed = newSpeed;
}
