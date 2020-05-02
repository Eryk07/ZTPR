#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H
#include "factor.h"
#include "fan.h"
#include <iostream>
#include <vector>


class AirConditioning : public Factor
{
public:
    AirConditioning();

    std::vector<Fan> fans;

    double changeTemperature() override;
    double changeHumidity() override;

};

#endif // AIRCONDITIONING_H
