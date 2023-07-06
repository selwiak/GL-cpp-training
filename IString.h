#include <iostream>
#include <memory>

class IString {  
    public:
    virtual ~IString() = default;
    virtual const char *toString() const = 0;
    virtual unsigned int length() const = 0;
    virtual const IString &insert(const IString &str, size_t pos) = 0;
    virtual const IString &append(const IString &str) = 0;
    virtual const IString &prepend(const IString &str) = 0;
    virtual IString &operator=(const IString &rhs) = 0;
    virtual IString &operator+(const IString& rhs) = 0;
};