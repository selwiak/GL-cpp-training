#ifndef ICAR_H
#define ICAR_H

#include <string>
#include <memory>
#include "IEngine.h"
#include "IGear.h"

// Car 
class Car {
public:
    Car(std::unique_ptr<IEngine> p_engine, std::unique_ptr<IGear> p_gear)
    : p_engine(std::move(p_engine)), p_gear(std::move(p_gear)) {}

    virtual std::string getCarType() const = 0;
    const IEngine *getEngine() const {
        return p_engine.get();
    }
    const IGear *getGear() const {
        return p_gear.get();
    }
    virtual ~Car() {}

protected:
    std::unique_ptr<IEngine> p_engine;
    std::unique_ptr<IGear> p_gear;
};

#endif // ICAR_H
