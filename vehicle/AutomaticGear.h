#ifndef AUTOMATIC_GEAR_H
#define AUTOMATIC_GEAR_H

#include "IGear.h"

class AutomaticGear final : public IGear {
public:
    std::string getGearType() const override {
        return "Automatic";
    }
};

#endif // AUTOMATIC_GEAR_H
