#ifndef FACTOR_H
#define FACTOR_H


class Factor
{
public:
    Factor();
    virtual double changeTemperature(double roomTemperature, double roomVolume) = 0;
    virtual double changeHumidity(double roomHumidity, double roomVolume) = 0;
    virtual double changeCO2() = 0;
};

#endif // FACTOR_H
