#pragma once

class Radio
{

protected:
    int lastRSSI;

public:
    Radio();
    virtual void emettre(unsigned char* data, unsigned int taille) = 0;
    virtual int recevoir(unsigned char* data, unsigned int taille) = 0;
    virtual int getLastRSSI();
    virtual ~Radio();
};