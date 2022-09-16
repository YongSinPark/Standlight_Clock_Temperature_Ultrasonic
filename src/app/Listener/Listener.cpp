#include "Listener.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

Listener::Listener(Button *modeButton, Button *powerButton, 
                   Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic* ultrasonic, 
                   Button *motorButton, Button *timerButton)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultrasonic = ultrasonic;
    this->motorButton = motorButton;
    this->timerButton = timerButton;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(dht11->dhtData.Temp < 30)
    {
        if (modeButton->getState() == RELEASE_ACTIVE)
        {
            cout << "mode button" << endl;
            controller->updateEvent("modeButton");
        }

        if (powerButton->getState() == RELEASE_ACTIVE)
        {
            cout << "power button" << endl;
            controller->updateEvent("powerButton");
        }

        if (timerButton->getState() == RELEASE_ACTIVE)
        {
            cout << "timer button" << endl;
            controller->updateEvent("timerButton");
        }

        if (clockCheck->isUpdate())
        {  
            static unsigned int prevClocktime = 0;
            if(millis() - prevClocktime > 1000)
            {
                prevClocktime= millis();
                controller->updateEvent("clockUpdate");
            }
        }
    }
    if (motorButton->getState() == RELEASE_ACTIVE)
    {
        cout << "motor button" << endl;
        controller->updateEvent("motorButton");
    }

    static unsigned int prevTempHumidTime = 0;
    if (millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltraDistanceTime = 0;
    if(millis() - prevUltraDistanceTime > 2000)
    {
        prevUltraDistanceTime= millis();
        int distance = ultrasonic->readDistance();
       
        controller->updateDistance(distance);
    }
}