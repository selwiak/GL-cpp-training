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
        text = new char[strlen(str) + 1];
        strcpy(text, str);
        text[strlen(str)] = '\0';

        cout << "Created object: " << text << endl;
    }
}

//copy constructor
String::String(const String &str)
{
    // get length of original string
    text = new char[strlen(str.text) + 1];
    // copy original string
    strcpy(text, str.text);

    cout << "Object copied: " << text << endl;
}

//move constructor
String::String(String &&str)
{
    //copy data
    text = str.text;
    //clear original object
    str.text = nullptr;

    cout << "Object moved: " << text << endl;
}

String::~String()
{
    delete text;
}

const char* String::toString() const
{  
    return text;
}

ostream & operator<< (ostream& os, const String &s) 
{
   return os << s.text << endl;
}
