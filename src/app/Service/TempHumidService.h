#ifndef __TEMPHUMIDSERVICE_H__
#define __TEMPHUMIDSERVICE_H__

#include "DHT_Data.h"
#include "TempHumidView.h"
#include "Motor.h"
class TempHumidService
{
private:
    TempHumidView *tempHumiView;
    Motor* motor;

public:
    TempHumidService(TempHumidView *tempHumiView, Motor* motor);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
    void updateState(std::string strBtn);
};

#endif /* __TEMPHUMIDSERVICE_H__ */