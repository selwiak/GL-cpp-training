#ifndef ICAR_H
#define ICAR_H

#include <string>
#include <memory>
#include "IEngine.h"
#include "IGear.h"

// Car 
class Car {
public:
    Car(IEngine* engine, IGear* gear)
        : engine(engine), gear(gear) {}

    virtual std::string getCarType() const = 0;
    const IEngine* getEngine() const {
        return engine;
    }
    const IGear* getGear() const {
        return gear;
    }
    virtual ~Car() {}

protected:
    IEngine* engine;
    IGear* gear;
};

#endif // ICAR_H
