#ifndef ICAR_H
#define ICAR_H

#include <string>
#include <memory>
#include "IEngine.h"
#include "IGear.h"

// Car 
class Car {
public:
    Car(Engine* engine, Gear* gear)
        : engine(engine), gear(gear) {}

    virtual std::string getCarType() const = 0;
    const Engine* getEngine() const {
        return engine;
    }
    const Gear* getGear() const {
        return gear;
    }
    virtual ~Car() {}

protected:
    Engine* engine;
    Gear* gear;
};

#endif // ICAR_H
