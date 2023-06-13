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
    unsigned int length() const;
    friend std::ostream & operator<< (std::ostream& os, const String &s);
};
