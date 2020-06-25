#ifndef FACTOR_H
#define FACTOR_H

/** Factor class, which is inherited by People and Airconditioning factors */
class Factor
{
public:
    Factor();
    /**
     * Change temperature in room simulation
     * @param roomTemperature current room temperature
     * @param roomVolume room volume
     * @return calculated temperature
     */
    virtual double changeTemperature(double roomTemperature, double roomVolume) = 0;
    /**
     * Change humidity in room simulation
     * @param roomHumidity current room humidity
     * @param roomVolume room volume
     * @return calculated humidity
     */
    virtual double changeHumidity(double roomHumidity, double roomVolume) = 0;
    /**
     * Change CO2 in room simulation
     * @return calculated CO2
     */
    virtual double changeCO2() = 0;
};

#endif // FACTOR_H
