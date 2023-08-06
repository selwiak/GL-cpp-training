#ifndef IGEAR_H
#define IGEAR_H

#include <string>

// Gear interface
class IGear {
public:
    virtual std::string getGearType() const = 0;
    virtual ~IGear() = default;
};

#endif // IGEAR_H
