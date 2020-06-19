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

    std::vector<Person> people;

    double changeTemperature() override;
    double changeHumidity() override;
    double changeCO2() override;
};

#endif // PEOPLE_H
