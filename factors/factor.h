#ifndef FACTOR_H
#define FACTOR_H


class Factor
{
public:
    Factor();
    virtual double changeTemperature() = 0;
    virtual double changeHumidity() = 0;
    virtual double changeCO2() = 0;
};

#endif // FACTOR_H
