#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

// function to check string length
unsigned int stringLength(char* const str)
{
    unsigned int count = 0;
    
    if(nullptr != str)
    {
        while(str[count] != '\0')
        {
            count++;
        }
    }
    else
    {
        // nullptr
    }
    
    return count; 
}

String::String()
{
    text = nullptr;
    cout << "Object created." << endl;
}

String::String(char* str)
{
    // check if there initial value is given
    if(str == nullptr)
    {
        // no initial value, create empty object
        text = nullptr;
    }
    else
    {
        // initial value given, copy it to string
        size = stringLength(str) + 1;
        text = make_unique<char[]>(size);
        //text = make_unique<char[]>(strlen(str) + 1);
        strcpy(text.get(), str);
        text[size] = '\0';

        cout << "Created object: " << text.get() << endl;
    }
}

//copy constructor
String::String(const String &str)
{
    if(&str != nullptr)
    {
        // get length of original string
        size = str.size;
        text = make_unique<char[]>(size);
        // copy original string
        strcpy(text.get(), str.text.get());

        cout << "Object copied: " << text.get() << endl;
    }
    else
    {
        //
    }
}

//move constructor
String::String(String&& str) : text(std::move(str.text)) {
    size = str.size;
    str.text = nullptr;
}

String::~String(){}

const char* String::toString() const
{  
    return text.get();
}

ostream & operator<< (ostream& os, const String &s) 
{
   return os << s.text.get() << endl;
}
