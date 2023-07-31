#ifndef JEEP_H
#define JEEP_H

#include "ICar.h"

template <typename EngineType, typename GearType>
class Jeep : public Car {
public:
    Jeep(std::unique_ptr<EngineType> engine, std::unique_ptr<GearType> gear)
        : Car(std::move(engine), std::move(gear)) {}

    std::string getCarType() const override {
        return "Jeep";
    }
};

#endif // JEEP_H
