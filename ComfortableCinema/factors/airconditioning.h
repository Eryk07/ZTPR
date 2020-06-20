#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H
#include "factor.h"
#include "fan.h"
#include <iostream>
#include <vector>


class AirConditioning : public Factor
{
public:
    AirConditioning(int fansCount);

    std::vector<Fan> fans;

    double changeTemperature(double roomTemperature, double roomVolume) override;
    double changeHumidity() override;
    double changeCO2() override;

};

#endif // AIRCONDITIONING_H
