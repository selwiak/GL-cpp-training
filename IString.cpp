#include <iostream>
#include "IString.h"

std::ostream &operator<<(std::ostream &os, const IString &obj) 
{
    obj.print(os);
    return os;
}