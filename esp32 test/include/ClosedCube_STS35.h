/*#ifndef CLOSEDCUBE_STS35_ARDUINO_H
#define CLOSEDCUBE_STS35_ARDUINO_H

#include "ClosedCube_I2C.h"

namespace ClosedCube {

    namespace Sensor {

        typedef enum {
            STS35_REPEATABILITY_HIGH,
            STS35_REPEATABILITY_MEDIUM,
            STS35_REPEATABILITY_LOW,
        } STS35_Repeatability;

        class STS35 {

        public:
            STS35();
            STS35(uint8_t address);
            STS35(ClosedCube::Driver::I2CDevice device);

            void address(uint8_t address);

            void heaterOn();
            void heaterOff();

            void clockStrechingOn();
            void clockStrechingOff();

            void setRepeatability(STS35_Repeatability);

            float readTemperature();
            float readT();

        private:
            ClosedCube::Driver::I2CDevice _sensor;
            
            STS35_Repeatability _repeatability = STS35_REPEATABILITY_HIGH;
            bool _clockStreching = true;
            bool _singleShotMode = true;

            uint8_t readSignleShot(byte *buf);

            float calculateTemperature(uint16_t t_raw);
            uint8_t calculateCrc(uint8_t data[]);
        };
    }
}


#endif*/