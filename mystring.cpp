#include <iostream>
#include "mystring.h"

using namespace std;

String::String()
{
    text = "Default constructor";
    cout << text << endl;
}

String::String(string str)
{
    text = str;
    cout << text << endl;
}

String::~String()
{
    text = "Object destroyed";
    cout << text << endl;
}

string* String::toString()
{
    string* p = &text;
    return p;
}

 ostream & operator<< (ostream& os, const String &s) {
   return os << s.text << " overloaded " << endl;
 }
