#include "ClockView.h"
#include <iostream>

using namespace std;

ClockView::ClockView(LCD *lcd)
{
    this->lcd = lcd;
    //timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d",
            timeData->tm_hour,
            timeData->tm_min,
            timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}

void ClockView::clockTimer()
{
    static unsigned int prevTimerTime = 0;
    static int hour = 0, min = 0, sec = 0;
    char buff[30];

    if(millis() - prevTimerTime > 1000)
    {
        sec++;
        prevTimerTime = millis();

        if(sec == 60) 
        {
            sec = 0;
            min++;
        }
        if(min == 60) 
        {
            min = 0;
            hour++;
        }
        if(hour == 24) hour = 0;

        cout << ":" << hour << ":" << min << ":" << sec << endl;
        sprintf(buff, "%02d:%02d:%02d", hour, min, sec);
        lcd->WriteStringXY(1, 0, buff);
    }
}