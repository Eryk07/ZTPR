#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <random>
#include <vector>

#include "factor.h"
#include "person.h"

/** Class of people factor, which is used to calculate simulation */
class People : public Factor
{
public:
    /** Constructor of people class, using normal distribution to set people parameters
    * @param peopleCount number of people
    */
    People(int peopleCount);

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

    std::vector<Person> getPeople() const;
    void setPeople(const std::vector<Person> &value);

private:
    ///Vector of people
    std::vector<Person> people;

    ///Constant average person thermal resistance
    const double thermalResist = 0.25;
    ///Constant average person breath volume
    const double breath = 0.0005;
    ///Constant air density in kg/m^3
    const double airDens = 1.2;     // kg/m3
};

#endif // PEOPLE_H
