#ifndef GAS_ENGINE_H
#define GAS_ENGINE_H

#include "IEngine.h"

class GasEngine final : public IEngine {
public:
    GasEngine(int p_cylinders) : m_cylinders(p_cylinders) {}

    std::string getFuelType() const override {
        return "Gas";
    }

    int getNumberOfCylinders() const override {
        return m_cylinders;
    }

private:
    int m_cylinders;
};

#endif // GAS_ENGINE_H
