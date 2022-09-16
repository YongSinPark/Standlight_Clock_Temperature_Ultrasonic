#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT_Data.h"
#include "TempHumidService.h"

class Controller
{
private:
    int lightState;
    Service *service;
    ClockService *clockService;
    TempHumidService *tempHumidService;
    int clockState;

public:
    Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumiService);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);
};

#endif /* __CONTROLLER_H__ */