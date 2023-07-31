#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV : public Car {
public:
    SUV(Engine* engine, Gear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "SUV";
    }
};

#endif // SUV_H
