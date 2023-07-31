#ifndef SEDAN_H
#define SEDAN_H

#include "ICar.h"

template <typename EngineType, typename GearType>
class Sedan : public Car {
public:
    Sedan(std::unique_ptr<EngineType> engine, std::unique_ptr<GearType> gear)
        : Car(std::move(engine), std::move(gear)) {}

    std::string getCarType() const override {
        return "Sedan";
    }
};

#endif // SEDAN_H
