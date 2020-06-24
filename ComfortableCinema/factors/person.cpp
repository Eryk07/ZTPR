#include "person.h"

Person::Person(double temperature, double CO2, double humidity)
{
    this->temperature = temperature;
    this->CO2 = CO2;
    this->humidity = humidity;
}

double Person::getTemperature() const
{
    return temperature;
}

void Person::setTemperature(double value)
{
    temperature = value;
}

double Person::getHumidity() const
{
    return humidity;
}

void Person::setHumidity(double value)
{
    humidity = value;
}

double Person::getCO2() const
{
    return CO2;
}

void Person::setCO2(double value)
{
    CO2 = value;
}
