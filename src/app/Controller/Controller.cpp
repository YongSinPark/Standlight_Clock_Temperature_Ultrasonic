#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumiService)
{
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumiService;
    this->lightState = LIGHT_OFF;
    clockState = 0;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if (strBtn == "motorButton")
    {
        tempHumidService->updateState("motorButton");
    }

    if (strBtn == "timerButton")
    {
        clockState = !clockState;
    }

    if (strBtn == "clockUpdate")
    {
        if(clockState) clockService->updateEvent_timer();
        if(!clockState) clockService->updateEvent();
    }
    
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}