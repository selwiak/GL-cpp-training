#ifndef SEDAN_H
#define SEDAN_H

#include <memory>
#include "Car.h"

class Sedan final: public Car {
public:
    Sedan(std::unique_ptr<IEngine> p_engine, std::unique_ptr<IGear> p_gear)
        : Car(std::move(p_engine), std::move(p_gear)) {}

    std::string getCarType() const override {
        return "Sedan";
    }
};

#endif // SEDAN_H
