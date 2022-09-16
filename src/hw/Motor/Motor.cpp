#include "Motor.h"

Motor::Motor(int pin)
    : pinNumber(pin), motorState(OFF)
{
    wiringPiSetup();
    pinMode(pinNumber, OUTPUT);
    softPwmStop(pinNumber);
}

Motor::~Motor()
{

}

void Motor::writePin(bool pinState)
{
    digitalWrite(pinNumber, (int)pinState);
}

void Motor::motorOn()
{
    softPwmCreate(pinNumber, 0, 100);
    softPwmWrite(pinNumber, 99);
}

void Motor::motorOff()
{
    softPwmStop(pinNumber);
}