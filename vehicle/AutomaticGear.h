#ifndef AUTOMATIC_GEAR_H
#define AUTOMATIC_GEAR_H

#include "IGear.h"

class AutomaticGear : public Gear {
public:
    std::string getGearType() const override {
        return "Automatic";
    }
};

#endif // AUTOMATIC_GEAR_H
