#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

class Motor
{
private:
    const bool ON = 1;
    const bool OFF = 0;
    int pinNumber;
    bool motorState;

    void writePin(bool pinState);

public:
    Motor(int pin);
    virtual ~Motor();
    void motorOn();
    void motorOff();
};

#endif