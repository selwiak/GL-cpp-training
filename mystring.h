#include <iostream>

using namespace std;

class String {
    char* text;
    
    public:
    String();
    String(char* str);
    ~String();
    char** toString();
    friend ostream & operator<< (ostream& os, const String &s);
};
