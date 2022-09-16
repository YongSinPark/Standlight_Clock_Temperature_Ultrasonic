#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"
#include "Motor.h"

class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    ClockCheck *clockCheck;
    Controller *controller;
    DHT11 *dht11;
    UltraSonic* ultrasonic;
    Button *motorButton;
    Button *timerButton;

public:
    Listener(Button *modeButton, Button *powerButton,
             Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic* ultrasonic, 
             Button *motorButton, Button *timerButton);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
