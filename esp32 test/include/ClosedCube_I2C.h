/*#ifndef _CLOSEDCUBE_I2C_H
#define _CLOSEDCUBE_I2C_H

#ifndef CC_ARDUINO
#define CC_ARDUINO 1
#include "Arduino.h"
#include <Wire.h>
#endif

#define CC_I2C_DRIVER_VERSION 0x1012
#define CC_I2C_RW_DELAY_MS 1
#define CC_I2C_ERROR_NOT_DEFINED 0xFF
#define CC_I2C_CRC_ERROR 0xF0
#define CC_I2C_ERROR_REQ_INCORRECT 0xA0
#define CC_I2C_OK 0x00

namespace ClosedCube
{
    namespace Driver
    {

        class I2CDevice
        {

        public:
#if defined(CC_ARDUINO)
            I2CDevice(TwoWire *wire = &Wire);
#endif

            I2CDevice(uint8_t address);

            void init();

            uint8_t readByte();
            uint16_t readWord();
            uint32_t readInt();

            int8_t readS8();
            int16_t readS16();
            int32_t readS32();

            void readBytes(byte *buf, uint8_t size);
            void readBytes(byte *buf, uint8_t size, bool stop);
            void writeBytes(byte *buf, uint8_t size);
            void writeBytes(byte *buf, uint8_t size, bool stop);

            void writeByte(uint8_t value);
            void writeByte(uint8_t value, bool stop);
            void writeWord(uint16_t value);
            void writeWord(uint16_t value, bool stop);
            void writeInt(uint32_t value);
            void writeInt(uint32_t value, bool stop);

            uint8_t readByteFromReg(uint8_t reg, uint16_t delay_ms);
            uint8_t readByteFromReg(uint8_t reg);
            uint16_t readWordFromReg(uint8_t reg, uint16_t delay_ms);
            uint16_t readWordFromReg(uint8_t reg);

            void writeByteToReg(uint8_t reg, uint8_t value);
            void writeWordToReg(uint8_t reg, uint16_t value);


            int8_t readS8FromReg(uint8_t reg, uint16_t delay_ms);
            int8_t readS8FromReg(uint8_t reg);
            void writeS8ToReg(uint8_t reg, int8_t value);

            /*
            uint16_t readRegU16(uint8_t reg, uint16_t delay_ms);
            uint16_t readRegU16(uint8_t reg);
            

            void address(uint8_t address) { _address = address; }

            uint8_t lastErrorCode();

            void printI2CSettings();

        private:
            uint8_t _address;
            uint8_t _errorCode;

#if defined(CC_ARDUINO)
            TwoWire *_wire;
#endif

            void clearError();
        };

    }; // namespace Driver
};     // namespace ClosedCube

#endif*/