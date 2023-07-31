#ifndef DIESEL_ENGINE_H
#define DIESEL_ENGINE_H

#include "IEngine.h"

class DieselEngine : public Engine {
public:
    DieselEngine(int cylinders) : cylinders(cylinders) {}

    std::string getFuelType() const override {
        return "Diesel";
    }

    int getNumberOfCylinders() const override {
        return cylinders;
    }

private:
    int cylinders;
};

#endif // DIESEL_ENGINE_H
