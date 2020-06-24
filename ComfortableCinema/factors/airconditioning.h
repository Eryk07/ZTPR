#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H
#include "factor.h"
#include "fan.h"
#include <iostream>
#include <vector>


class AirConditioning : public Factor
{
public:
    AirConditioning(int fansCount, double initSpeed);

    double changeTemperature(double roomTemperature, double roomVolume) override;
    double changeHumidity(double roomHumidity, double roomVolume) override;
    double changeCO2() override;
    std::vector<Fan> getFans() const;
    void setFans(const std::vector<Fan> &value);

private:
    std::vector<Fan> fans;
};

#endif // AIRCONDITIONING_H
