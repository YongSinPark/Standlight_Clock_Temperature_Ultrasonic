#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "UltraSonic.h"
#include "Motor.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button modeButton(27);
    Button powerButton(28);
    Button timerButton(29);
    Button motorButton(6);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    Motor motor(26);
    UltraSonic ultraSonic(5, 4);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView tempHumidView(&led1, &led2, &led3, &led4, &led5, &lcd, &motor);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&tempHumidView, &motor);
    Controller control(&service, &clockSerivce, &tempHumidService);
    Listener listener(&modeButton, &powerButton, &control, &clockCheck, &dht, &ultraSonic, &motorButton, &timerButton);
    
    while (1)
    {
        listener.checkEvent();
        if(dht.dhtData.Temp < 30) view.lightView();

        delay(10);
    }

    return 0;
}