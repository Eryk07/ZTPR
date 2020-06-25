#ifndef PERSON_H
#define PERSON_H

/** Person class, which belongs to People object */
class Person
{
public:
    /** Constructor of Person class
    * @param temperature init temperature of person
    * @param CO2 init temperature of person
    * @param humidity init temperature of person
    * */
    Person(double temperature, double CO2, double humidity);

    double getTemperature() const;
    void setTemperature(double value);

    double getHumidity() const;
    /** Setter of person humidity
    * @param value must be higher than 0
    * */
    void setHumidity(double value);

    double getCO2() const;
    /** Setter of person CO2
    * @param value must be higher than 0
    * */
    void setCO2(double value);

private:
    /// person temperature
    double temperature;
    /// person humidity
    double humidity;
    /// person CO2
    double CO2;

};

#endif // PERSON_H
