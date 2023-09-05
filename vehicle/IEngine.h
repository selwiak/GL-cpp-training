#ifndef IENGINE_H
#define IENGINE_H

#include <string>

// Engine interface
class IEngine {
public:
    virtual std::string getFuelType() const = 0;
    virtual int getNumberOfCylinders() const = 0;
    virtual ~IEngine() = default;
};

#endif // IENGINE_H
