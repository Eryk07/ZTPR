#ifndef PEOPLE_H
#define PEOPLE_H
#include "factor.h"
#include "person.h"
#include <iostream>
#include <vector>

class People : public Factor
{
public:
    People();

    std::vector<Person> people;

    double changeTemperature() override;
    double changeHumidity() override;
    double changeCO2() override;
};

#endif // PEOPLE_H
