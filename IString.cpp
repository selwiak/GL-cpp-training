#include <iostream>
#include "IString.h"

namespace str
{
    std::ostream &operator<<(std::ostream &os, const IString &obj) 
    {
        obj.print(os);
        return os;
    }   
}