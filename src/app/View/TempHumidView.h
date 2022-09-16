#ifndef __TEMPHUMIDVIEW_H__
#define __TEMPHUMIDVIEW_H__

#include "LCD.h"
#include "Led.h"
#include "Motor.h"
class TempHumidView
{
private:
    LCD *lcd;
    Motor *motor;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;

public:
    TempHumidView(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd, Motor *motor);
    virtual ~TempHumidView();
    void setTempHumidData(float temp, float humid);
    void updateTempEvent(float temp, float humid);
    void updateMotorState(std::string strBtn);

};

#endif /* __TEMPHUMIDVIEW_H__ */