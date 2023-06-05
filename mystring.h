#include <iostream>
#include <memory>

class String {
    private:
    std::unique_ptr<char[]> text;
    unsigned int size = 0;
    
    public:
    String();
    String(char* str);
    String(const String &str);
    String(String &&str);
    ~String();
    const char* toString() const;
    friend std::ostream & operator<< (std::ostream& os, const String &s);
    friend unsigned int stringLength(const String mystring);
};
