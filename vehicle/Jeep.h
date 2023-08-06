#ifndef JEEP_H
#define JEEP_H

#include "Car.h"

class Jeep final : public Car {
public:
    Jeep(IEngine* engine, IGear* gear)
        : Car(engine, gear) {}

    std::string getCarType() const override {
        return "Jeep";
    }
};

#endif // JEEP_H
