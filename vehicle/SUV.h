#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV final: public Car {
public:
    SUV(IEngine* engine, IGear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "SUV";
    }
};

#endif // SUV_H
