#include "Service.h"
#include <iostream>

using namespace std;

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    distanceLight = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(distanceLight) {
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            };
        break;
        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(distanceLight) {
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(distanceLight) {
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(distanceLight) {
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(distanceLight) {
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
     static int distance_level_count = 0;
    cout << "distance : " << distance << "\tcount : " << distance_level_count << endl;

    if(distance > 100 || distance < 0)
    {
        distance_level_count++;
        if (distance_level_count > 10)
        {   
            distanceLight = false;
            view->setState(LIGHT_OFF);
        }
    }
    else 
    {
        distance_level_count = 0;

        distanceLight = true;
        view->setState(lightState);
    }
}