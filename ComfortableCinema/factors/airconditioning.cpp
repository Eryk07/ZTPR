#include "airconditioning.h"

AirConditioning::AirConditioning(int fansCount, double initSpeed)
{
    for (int i = 0; i<fansCount; ++i)
        this -> fans.push_back(Fan(initSpeed));
}

double AirConditioning::changeTemperature(double roomTemperature, double roomVolume)
{
    double fanHeat = 0;

    for (unsigned int i=0; i<this->fans.size(); ++i)
        fanHeat += (this->fans[i].getSpeed()*roomTemperature);

    return  fanHeat/roomVolume;
}

double AirConditioning::changeHumidity(double roomHumidity, double roomVolume)
{
    double flow = 0;

    for (unsigned int i=0; i<this->fans.size(); ++i)
        flow += (this->fans[i].getSpeed());

    return (flow/roomVolume)*roomHumidity;
}

double AirConditioning::changeCO2()
{
    return 0;
}

std::vector<Fan> AirConditioning::getFans() const
{
    return fans;
}

void AirConditioning::setFans(const std::vector<Fan> &value)
{
    fans = value;
}
