#include <iostream>

using namespace std;

class String {
    string text;
    
    public:
    String();
    String(string);
    ~String();
    string* toString();
    friend ostream & operator<< (ostream& os, const String &s);
};
