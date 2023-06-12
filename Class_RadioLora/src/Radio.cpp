#include "Radio.hpp"

Radio::Radio() {
    this->lastRSSI = 0;
}

int Radio::getLastRSSI() {
    return this->lastRSSI;
}

Radio::~Radio() {

}