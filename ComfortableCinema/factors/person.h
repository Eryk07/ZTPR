#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(double temperature, double CO2, double humidity);

    double getTemperature() const;
    void setTemperature(double value);

    double getHumidity() const;
    void setHumidity(double value);

    double getCO2() const;
    void setCO2(double value);

private:
    double temperature;
    double humidity;
    double CO2;

};

#endif // PERSON_H
