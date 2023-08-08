#ifndef SUV_H
#define SUV_H

#include <memory>
#include "Car.h"

class SUV final: public Car {
public:
    SUV(std::unique_ptr<IEngine> p_engine, std::unique_ptr<IGear> p_gear)
        : Car(std::move(p_engine), std::move(p_gear)) {}

    std::string getCarType() const override {
        return "SUV";
    }
};

#endif // SUV_H
