#include "people.h"

People::People(int peopleCount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> temperatureDistribution(36.8, 0.3);    //  stats from wikipedia
    std::normal_distribution<double> CO2Distribution(0.138, 0.01);    //  person by average generate 0,138 kg of CO2 per 2h (average movie)
    std::normal_distribution<double> humidityDistribution(0.027, 0.007); //     person by average loose 0,027 kg of water with breath per 2h
    double generatedTemperature, generatedCO2, generatedHumidity;

    for (int i=0; i<peopleCount; ++i)
    {
        generatedTemperature = temperatureDistribution(generator);
        generatedCO2 = CO2Distribution(generator);
        generatedHumidity = humidityDistribution(generator);
        this->people.push_back(Person(generatedTemperature, generatedCO2, generatedHumidity));
    }
}

double People::changeTemperature(double roomTemperature, double roomVolume)
{
    double peopleHeat = 0;

    for (unsigned int i=0; i<this->people.size(); ++i)
        peopleHeat += (this->people[i].getTemperature() - roomTemperature) / this->thermalResist;

    return  peopleHeat/roomVolume;
}

double People::changeHumidity(double roomHumidity, double roomVolume)
{
    double dryAirMass = roomVolume * this->airDens;
    double wetAirMass = 0;

    for (unsigned int i=0; i<this->people.size(); ++i)
        wetAirMass += this->people[i].getHumidity();

    return wetAirMass/dryAirMass;
}

double People::changeCO2()
{
    double CO2Mass = 0;

    for (unsigned int i=0; i<this->people.size(); ++i)
        CO2Mass += this->people[i].getCO2();

    return CO2Mass;
}

std::vector<Person> People::getPeople() const
{
    return people;
}

void People::setPeople(const std::vector<Person> &value)
{
    people = value;
}
