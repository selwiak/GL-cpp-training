#ifndef IGEAR_H
#define IGEAR_H

#include <string>
#include <memory>

// Gear interface
class Gear {
public:
    virtual std::string getGearType() const = 0;
    virtual ~Gear() = default;
};

#endif // IGEAR_H
