#ifndef MANUAL_GEAR_H
#define MANUAL_GEAR_H

#include "IGear.h"

class ManualGear : public Gear {
public:
    std::string getGearType() const override {
        return "Manual";
    }
};

#endif // MANUAL_GEAR_H
