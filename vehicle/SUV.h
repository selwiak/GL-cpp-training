#ifndef SUV_H
#define SUV_H

#include "ICar.h"

template <typename EngineType, typename GearType>
class SUV : public Car {
public:
    SUV(std::unique_ptr<EngineType> engine, std::unique_ptr<GearType> gear)
        : Car(std::move(engine), std::move(gear)) {}

    std::string getCarType() const override {
        return "SUV";
    }
};

#endif // SUV_H
