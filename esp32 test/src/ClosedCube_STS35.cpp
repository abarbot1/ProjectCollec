/*#include <stdint.h>
#include "ClosedCube_STS35.h"

ClosedCube::Sensor::STS35::STS35() {
}

ClosedCube::Sensor::STS35::STS35(ClosedCube::Driver::I2CDevice device): _sensor(device) {    
}

ClosedCube::Sensor::STS35::STS35(uint8_t address) {
    _sensor.address(address);
}

void ClosedCube::Sensor::STS35::address(uint8_t address) {
    _sensor.address(address);
}

float ClosedCube::Sensor::STS35::calculateTemperature(uint16_t rawValue)
{
    return 175.0f * (float)rawValue / 65535.0f - 45.0f;
}

void ClosedCube::Sensor::STS35::setRepeatability(ClosedCube::Sensor::STS35_Repeatability repeatability) {
    _repeatability = repeatability;
}

float ClosedCube::Sensor::STS35::readT() {
    return readTemperature();
}

float ClosedCube::Sensor::STS35::readTemperature() {
    byte buf[3];
    uint8_t stat;
    if( _singleShotMode ) {
        stat = readSignleShot(buf);
    } else {
        stat = 0; // PERIODIC MODE
    }

    float result = 0.0;

    if( stat == 0 ) {
        uint16_t t_raw = buf[0] << 8 | buf[1];
        uint8_t checksum = buf[2];

        if (calculateCrc(buf) == checksum) {
            result = calculateTemperature(t_raw);
        }
    }

    return result;
}

uint8_t ClosedCube::Sensor::STS35::readSignleShot(byte *buf) {
    uint16_t cmd;
    switch (_repeatability) {
        case STS35_REPEATABILITY_HIGH:
            cmd = _clockStreching ? 0x2C06 : 0x2400;
            break;
        case STS35_REPEATABILITY_MEDIUM:
            cmd = _clockStreching ? 0x2C0D : 0x240B;
            break;
        case STS35_REPEATABILITY_LOW:
            cmd = _clockStreching ? 0x2C10 : 0x2416;
            break;
        default:
            cmd = _clockStreching ? 0x2C0D : 0x240B;
            break;
    }
    _sensor.writeWord(cmd);
    delay(5);
    _sensor.readBytes(buf,(uint8_t)3);

    return 0;
}

void ClosedCube::Sensor::STS35::clockStrechingOn() {
    _clockStreching = true;
}

void ClosedCube::Sensor::STS35::clockStrechingOff() {
    _clockStreching = false;
}

void ClosedCube::Sensor::STS35::heaterOn() {
    _sensor.writeWord(0x306D);
}

void ClosedCube::Sensor::STS35::heaterOff() {
    _sensor.writeWord(0x3066);
}

uint8_t ClosedCube::Sensor::STS35::calculateCrc(uint8_t data[])
{
    uint8_t bit;
    uint8_t crc = 0xFF;
    uint8_t dataCounter = 0;

    for (; dataCounter < 2; dataCounter++)
    {
        crc ^= (data[dataCounter]);
        for (bit = 8; bit > 0; --bit)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x131;
            else
                crc = (crc << 1);
        }
    }

    return crc;
}*/
