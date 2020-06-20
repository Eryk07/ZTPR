#include "people.h"

People::People(int peopleCount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> temperatureDistribution(36.8, 0.3);    //wikipedia
    std::normal_distribution<double> CO2Distribution(0.138, 0.01);    //  person by average generate 0,138 kg of CO2 per 2h (average movie)
    double generatedTemperature, generatedCO2;

    for (int i=0; i<peopleCount; ++i)
    {
        generatedTemperature = temperatureDistribution(generator);
        generatedCO2 = CO2Distribution(generator);
        this->people.push_back(Person(generatedTemperature, generatedCO2));
    }
}

double People::changeTemperature(double roomTemperature, double roomVolume)
{
    double peopleHeat = 0;

    for (unsigned int i=0; i<this->people.size(); ++i)
        peopleHeat += (this->people[i].temperature - roomTemperature) / this->thermalResist;

    if (peopleHeat != 0)
        return  peopleHeat/roomVolume;
    else
        return 0;
}

double People::changeHumidity()
{
    return 0;
}

double People::changeCO2()
{
    return 0;
}
