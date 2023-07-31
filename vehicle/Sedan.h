#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

class Sedan : public Car {
public:
    Sedan(Engine* engine, Gear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "Sedan";
    }
};

#endif // SEDAN_H
