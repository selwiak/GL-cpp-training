#include <iostream>
#include "string.h"

namespace str
{
    std::ostream &operator<<(std::ostream &os, const string &obj) 
    {
        obj.print(os);
        return os;
    }   
}