#ifndef RADIOLORA_HPP
#define RADIOLORA_HPP

#include "Radio.hpp"

class RadioLora : public Radio
{

public:
    RadioLora();
    virtual void emettre(unsigned char *data, unsigned int taille);
    virtual unsigned int recevoir(unsigned char* data,unsigned int taille);
    virtual ~RadioLora();
};

#endif