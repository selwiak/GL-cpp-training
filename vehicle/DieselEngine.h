#ifndef DIESEL_ENGINE_H
#define DIESEL_ENGINE_H

#include "IEngine.h"

class DieselEngine final : public IEngine {
public:
    DieselEngine(int p_cylinders) : m_cylinders(p_cylinders) {}

    std::string getFuelType() const override {
        return "Diesel";
    }

    int getNumberOfCylinders() const override {
        return m_cylinders;
    }

private:
    int m_cylinders;
};

#endif // DIESEL_ENGINE_H
