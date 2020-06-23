#ifndef FAN_H
#define FAN_H


class Fan
{
public:
    Fan(double speed);

    double speed;

    void changeSpeed(double newSpeed);
};

#endif // FAN_H
