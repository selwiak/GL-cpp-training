#include <iostream>

class String {
    private:
    char* text;
    
    public:
    String();
    String(char* str);
    String(const String &str);
    String(String &&str);
    ~String();
    const char* toString() const;
    friend std::ostream & operator<< (std::ostream& os, const String &s);
};
