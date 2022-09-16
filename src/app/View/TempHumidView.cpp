#include "TempHumidView.h"
#include <iostream>

using namespace std;

TempHumidView::TempHumidView(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd, Motor *motor)
{
    this->lcd = lcd;
    this->light1 = led1;
    this->light2 = led2;
    this->light3 = led3;
    this->light4 = led4;
    this->light5 = led5;
    this->motor = motor;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::updateTempEvent(float temp, float humid)
{
    char buff[30];

    lcd->backLightOn();

    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();

    sprintf(buff, "Warning!!!      ");
    lcd->WriteStringXY(0, 0, buff);
    sprintf(buff, "High temp!      ");
    lcd->WriteStringXY(1, 0, buff);
    printf("%.1f'C, %.1f%%\n",temp, humid);
}

void TempHumidView::setTempHumidData(float temp, float humid)
{   
    char buff[30];

    sprintf(buff, "%.1f'C%%", temp);
    lcd->WriteStringXY(0, 10, buff);
    sprintf(buff, "%.1f%%", humid);
    lcd->WriteStringXY(1, 10, buff);
    printf("%.1f'C, %.1f%%\n",temp, humid);
}

void TempHumidView::updateMotorState(std::string strBtn)
{   
    static int motorState = 0;

    if(strBtn == "motorButton") 
    {
        motorState = !motorState;
        cout << "motor state " << motorState << endl;
        if(motorState) motor->motorOff();
        if(!motorState) motor->motorOn();
    }

}