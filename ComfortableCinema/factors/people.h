#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <random>
#include <vector>

#include "factor.h"
#include "person.h"

class People : public Factor
{
public:
    People(int peopleCount);

    double changeTemperature(double roomTemperature, double roomVolume) override;
    double changeHumidity(double roomHumidity, double roomVolume) override;
    double changeCO2() override;

    std::vector<Person> getPeople() const;
    void setPeople(const std::vector<Person> &value);

private:
    std::vector<Person> people;

    const double thermalResist = 0.25;
    const double breath = 0.0005;
    const double airDens = 1.2;     // kg/m3
};

#endif // PEOPLE_H
