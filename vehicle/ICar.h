#ifndef ICAR_H
#define ICAR_H

#include <string>
#include <memory>
#include "IEngine.h"
#include "IGear.h"

// Car interface
class Car {
public:
    Car(std::unique_ptr<Engine> engine, std::unique_ptr<Gear> gear)
        : engine(std::move(engine)), gear(std::move(gear)) {}

    virtual std::string getCarType() const = 0;
    const Engine* getEngine() const {
        return engine.get();
    }
    const Gear* getGear() const {
        return gear.get();
    }
    virtual ~Car() = default;

protected:
    std::unique_ptr<Engine> engine;
    std::unique_ptr<Gear> gear;
};

#endif // ICAR_H
