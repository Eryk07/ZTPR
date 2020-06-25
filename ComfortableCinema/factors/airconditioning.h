#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H
#include "factor.h"
#include "fan.h"
#include <iostream>
#include <vector>

/** Class of air coinditioning factor, which is used to calculate simulation */
class AirConditioning : public Factor
{
public:
    /** Constructor of AirCondtitioning class
    * @param fansCount number of fans
    * @param initSpeed init speed of fans in air conditioning
    * */
    AirConditioning(int fansCount, double initSpeed);

    /**
     * Change temperature in room simulation
     * @param roomTemperature current room temperature
     * @param roomVolume room volume
     * @return calculated temperature
     */
    double changeTemperature(double roomTemperature, double roomVolume) override;
    /**
     * Change humidity in room simulation
     * @param roomHumidity current room humidity
     * @param roomVolume room volume
     * @return calculated humidity
     */
    double changeHumidity(double roomHumidity, double roomVolume) override;
    /**
     * Change CO2 in room simulation
     * @return calculated CO2
     */
    double changeCO2() override;

    std::vector<Fan> getFans() const;
    void setFans(const std::vector<Fan> &value);

private:
    /// Vector of fans in air conditioning
    std::vector<Fan> fans;
};

#endif // AIRCONDITIONING_H
