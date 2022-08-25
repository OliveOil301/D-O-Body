#ifndef HEAD_H
#define HEAD_H

#include <Arduino.h>
#include <communication.h>

class Head
{
private:
public:
    Head(void);
    void headSetup();

    Communication comm;

    void setNeckRotation(int angle);
    void setNeckTilt(int angle);

    void setHeadRotation(int angle);
    void setHeadNod(int angle);
    void setHeadTilt(int angle);
};

#endif