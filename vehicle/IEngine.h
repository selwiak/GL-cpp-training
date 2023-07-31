#ifndef IENGINE_H
#define IENGINE_H

#include <string>
#include <memory> 

// Engine interface
class Engine {
public:
    virtual std::string getFuelType() const = 0;
    virtual int getNumberOfCylinders() const = 0;
    virtual ~Engine() = default;
};

#endif // IENGINE_H
