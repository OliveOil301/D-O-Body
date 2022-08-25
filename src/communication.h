#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>

class Communication
{
private:
public:
    Communication(void);

    void sendHeadRotation(int angle);
    void sendHeadTilt(int angle);
    void sendSound(String soundTitle);
    void requestBatteryLevel();
};

#endif