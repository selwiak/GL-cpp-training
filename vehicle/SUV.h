#ifndef SUV_H
#define SUV_H

#include "Car.h"

class SUV final: public Car {
public:
    SUV(IEngine* m_engine, IGear* m_gear)
        : Car(m_engine, m_gear) {}

    std::string getCarType() const override {
        return "SUV";
    }
};

#endif // SUV_H
