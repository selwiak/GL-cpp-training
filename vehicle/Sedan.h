#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

class Sedan final: public Car {
public:
    Sedan(IEngine* engine, IGear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "Sedan";
    }
};

#endif // SEDAN_H
