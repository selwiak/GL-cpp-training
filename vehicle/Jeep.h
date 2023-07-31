#ifndef JEEP_H
#define JEEP_H

#include "Car.h"

class Jeep : public Car {
public:
    Jeep(Engine* engine, Gear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "Jeep";
    }
};

#endif // JEEP_H
