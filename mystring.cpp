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

String::~String()
{
    delete text;
}

const char* String::toString()
{
    const char* temp = "";

    // check if string is a nullptr
    if (nullptr != text)
    {   
        //if string is not a nullptr return original string
        temp = text;
    }
    else
    {
        //if string is a nullptr return empty string
    }
    
    return temp;
}

ostream & operator<< (ostream& os, const String &s) 
{
   return os << s.text << endl;
}
