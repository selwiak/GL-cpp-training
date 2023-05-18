#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

String::String()
{
    text = new char[1];
    text[0] = '\0';

    cout << "Object created." << endl;
}

String::String(char* str)
{
    if(str == nullptr)
    {
        text = new char[1];
        text[0] = '\0';
    }
    else
    {
        text = new char[strlen(str) + 1];
        strcpy(text, str);

        cout << "Created object: " << text << endl;
    }
}

String::~String()
{
    delete text;
}

char** String::toString()
{
    return &text;
}

ostream & operator<< (ostream& os, const String &s) 
{
   return os << s.text << endl;
}
