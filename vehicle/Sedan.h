#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

class Sedan final: public Car {
public:
    Sedan(IEngine* m_engine, IGear* m_gear)
        : Car(m_engine, m_gear) {}

    std::string getCarType() const override {
        return "Sedan";
    }
};

#endif // SEDAN_H
