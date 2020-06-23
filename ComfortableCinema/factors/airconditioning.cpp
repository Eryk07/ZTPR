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
        fanHeat += (this->fans[i].speed*roomTemperature);

    return  fanHeat/roomVolume;
}

double AirConditioning::changeHumidity(double roomHumidity, double roomVolume)
{
    double flow = 0;

    for (unsigned int i=0; i<this->fans.size(); ++i)
        flow += (this->fans[i].speed);

    return (flow/roomVolume)*roomHumidity;
}

double AirConditioning::changeCO2()
{
    return 0;
}
