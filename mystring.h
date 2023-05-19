#include <iostream>

class String {
    private:
    char* text;
    
    public:
    String();
    String(char* str);
    ~String();
    const char* toString();
    friend std::ostream & operator<< (std::ostream& os, const String &s);
};
