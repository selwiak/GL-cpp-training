#ifndef JEEP_H
#define JEEP_H

#include <memory>
#include "Car.h"

class Jeep final : public Car {
public:
    Jeep(std::unique_ptr<IEngine> p_engine, std::unique_ptr<IGear> p_gear)
        : Car(std::move(p_engine), std::move(p_gear)) {}

    std::string getCarType() const override {
        return "Jeep";
    }
};

#endif // JEEP_H
