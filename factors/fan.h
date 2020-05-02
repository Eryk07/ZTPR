#ifndef FAN_H
#define FAN_H


class Fan
{
public:
    Fan();

    int id;
    double speed;

    double changeTemperature();

private:
    void changeSpeed();
};

#endif // FAN_H
