#ifndef FAN_H
#define FAN_H


class Fan
{
public:
    Fan(double speed);

    double getSpeed() const;
    void setSpeed(double value);

private:
    double speed;
};

#endif // FAN_H
