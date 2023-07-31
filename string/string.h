#include <iostream>
#include <memory>

namespace str
{
    class string {  
        friend std::ostream &operator<<(std::ostream &os, const string &s);

        public:
        virtual ~string() = default;
        virtual const char *toString() const = 0;
        virtual unsigned int length() const = 0;
        virtual const string &insert(const string &str, size_t pos) = 0;
        virtual const string &append(const string &str) = 0;
        virtual const string &prepend(const string &str) = 0;
        virtual string &operator=(const string &rhs) = 0;
        virtual string &operator+(const string& rhs) = 0;
        virtual void print(std::ostream &os) const = 0;
        };
}