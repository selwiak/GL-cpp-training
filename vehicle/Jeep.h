#ifndef JEEP_H
#define JEEP_H

#include "Car.h"

class Jeep final : public Car {
public:
    Jeep(IEngine* m_engine, IGear* m_gear)
        : Car(m_engine, m_gear) {}

    std::string getCarType() const override {
        return "Jeep";
    }
};

#endif // JEEP_H
