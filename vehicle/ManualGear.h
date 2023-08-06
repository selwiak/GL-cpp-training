#ifndef MANUAL_GEAR_H
#define MANUAL_GEAR_H

#include "IGear.h"

class ManualGear final: public IGear {
public:
    std::string getGearType() const override {
        return "Manual";
    }
};

#endif // MANUAL_GEAR_H
