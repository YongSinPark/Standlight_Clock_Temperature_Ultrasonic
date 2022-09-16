#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *tempHumiView, Motor* motor)
{
    this->tempHumiView = tempHumiView;
    this->motor = motor;
}

TempHumidService::~TempHumidService()
{
}

void TempHumidService::updateEvent(DHT_Data dhtData)
{
    float temp, humid;

    static int cnt;

    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);
    
    if(temp >= 30) 
    {
        tempHumiView->updateTempEvent(temp, humid);
        if(cnt < 1) 
        {
            tempHumiView->updateMotorState("motorButton");
            cnt++;
        }
    }

    if(temp < 30) tempHumiView->setTempHumidData(temp, humid);
}

void TempHumidService::updateState(std::string strBtn)
{
    if (strBtn == "motorButton") tempHumiView->updateMotorState("motorButton");
}