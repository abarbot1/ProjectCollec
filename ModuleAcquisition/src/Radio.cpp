#include "Radio.hpp"

Radio::Radio() {
    this->lastRSSI = 10;
}

int Radio::getLastRSSI() {
    return this->lastRSSI;
}

Radio::~Radio() {

}