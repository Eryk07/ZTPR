#include "fan.h"

Fan::Fan(double speed)
{
    this->speed = speed;
}

double Fan::getSpeed() const
{
    return speed;
}

void Fan::setSpeed(double value)
{
    if (value > 0)
        speed = value;
}
