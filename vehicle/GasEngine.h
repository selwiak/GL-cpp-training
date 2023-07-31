#ifndef GAS_ENGINE_H
#define GAS_ENGINE_H

#include "IEngine.h"

class GasEngine : public Engine {
public:
    GasEngine(int cylinders) : cylinders(cylinders) {}

    std::string getFuelType() const override {
        return "Gas";
    }

    int getNumberOfCylinders() const override {
        return cylinders;
    }

private:
    int cylinders;
};

#endif // GAS_ENGINE_H
