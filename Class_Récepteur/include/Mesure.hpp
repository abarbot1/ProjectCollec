#ifndef MESURE_HPP
#define MESURE_HPP

class Mesure {

private:
    unsigned int idCapteur;
    char type;
    float payload;
    unsigned int batterie;
    unsigned int rssi;

public:
    unsigned int getIdCapteur() {return this->idCapteur;}
    char getType() {return this->type;}
    float getPayload() {return this->payload;}
    unsigned int getBatterie() {return this->batterie;} 
    unsigned int getRssi() {return this->rssi;}
    void setIdCapteur(unsigned int id) {this->idCapteur = id;}
    void setType(char type) {this->type = type;}
    void setPayload(float payload) {this->payload = payload;}
    void setBatterie(unsigned int batterie) {this->batterie = batterie;}
    void setRssi(unsigned int rssi) {this->rssi = rssi;}
    Mesure();
    ~Mesure();
};

#endif