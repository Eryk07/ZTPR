#ifndef FACTOR_H
#define FACTOR_H


class Factor
{
public:
    Factor();
    virtual double changeTemperature();
    virtual double changeHumidity();
    virtual double changeCO2();
};

#endif // FACTOR_H
