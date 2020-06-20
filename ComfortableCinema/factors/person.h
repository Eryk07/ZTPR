#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(double temperature, double CO2, double humidity);

    double temperature;
    double humidity;
    double CO2;

};

#endif // PERSON_H
