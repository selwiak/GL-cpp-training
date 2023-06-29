#include <iostream>
#include <memory>

class String {
    private:
    std::unique_ptr<char[]> text;
    unsigned int size = 0;
    
    public:
    String();
    String(char *str);
    String(const String &str);
    String(String &&str);
    ~String();
    const char *toString() const;
    unsigned int length() const;
    const String &insert(const String &str, size_t pos);
    const String &append(const String &str);
    const String &prepend(const String &str);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    String &operator=(const String &rhs);
    String &operator+(const String& rhs);
    static String fromInt(int value);
};
