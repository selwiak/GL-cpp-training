#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

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
        text = make_unique<char[]>(strlen(str) + 1);
        strcpy(text.get(), str);
        text[strlen(str)] = '\0';

        cout << "Created object: " << text.get() << endl;
    }
}

//copy constructor
String::String(const String &str)
{
    // get length of original string
    text = make_unique<char[]>(strlen(str.text.get()) + 1);
    // copy original string
    strcpy(text.get(), str.text.get());

    cout << "Object copied: " << text.get() << endl;
}

//move constructor
String::String(String&& str) : text(std::move(str.text)) {
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

unsigned int stringLength(const String mystring)
{
    unsigned int count = 0;

    while(mystring.text[count] !='\0')
    {
        count++;
    }

    return count; 
}
