#ifndef FAN_H
#define FAN_H

/** Fan class, which belongs to AirConditioning object */
class Fan
{
public:
    /** Constructor of Fan class
    * @param speed init speed of fan
    * */
    Fan(double speed);

    double getSpeed() const;
    /** Setter of fan speed
    * @param value must be higher than 0
    * */
    void setSpeed(double value);

private:
    /// Speed of fan
    double speed;
};

#endif // FAN_H
