#pragma once
#include <iostream>

class Cappyrano {

    public:
    Cappyrano();
    Cappyrano(double scan_rate);
    void mesureFluxSolaire(double &mesureFlux);
    void Update();
    ~Cappyrano();

    private :
        const double scan_rate_;
        double mesureFlux;
};