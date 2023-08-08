#ifndef ICAR_H
#define ICAR_H

#include <string>
#include <memory>
#include "IEngine.h"
#include "IGear.h"

// Car 
class Car {
public:
    Car(IEngine* m_engine, IGear* m_gear)
        : m_engine(m_engine), m_gear(m_gear) {}

    virtual std::string getCarType() const = 0;
    const IEngine* getEngine() const {
        return m_engine;
    }
    const IGear* getGear() const {
        return m_gear;
    }
    virtual ~Car() {}

protected:
    IEngine* m_engine;
    IGear* m_gear;
};

#endif // ICAR_H
