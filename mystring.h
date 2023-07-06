#include <iostream>
#include <memory>
#include "IString.h"

class String : public IString {
    private:
    std::unique_ptr<char[]> text;
    unsigned int size = 0;
    
    public:
    String();
    String(char *str);
    String(const String &str);
    String(String &&str);
    ~String();
    const char *toString() const override;
    unsigned int length() const override;
    const String &insert(const IString &str, size_t pos) override;
    const String &append(const IString &str) override;
    const String &prepend(const IString &str) override;
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    IString &operator=(const IString &rhs) override;
    IString &operator+(const IString& rhs) override;
    static String fromInt(int value);
    String &operator=(const String &rhs);
};
