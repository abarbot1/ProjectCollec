#pragma once
#include "ClosedCube_STS35.h"
#define STS35_I2C_ADDRESS 0x4B
class CapteurTemp
{
private:
    float temperature;
    ClosedCube::Sensor::STS35 sts35;

public:
    CapteurTemp();
    CapteurTemp(uint8_t adresse);
    float getTemperature();
    void aquerirTemperature();
    ~CapteurTemp();
};