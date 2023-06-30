#include <iostream>
#include <memory>

class StringInterface {  
    public:
    virtual ~StringInterface() = 0;
    virtual const char *toString() const = 0;
    virtual unsigned int length() const = 0;
    virtual const StringInterface &insert(const StringInterface &str, size_t pos) = 0;
    virtual const StringInterface &append(const StringInterface &str) = 0;
    virtual const StringInterface &prepend(const StringInterface &str) = 0;
    virtual StringInterface &operator=(const StringInterface &rhs) = 0;
    virtual StringInterface &operator+(const StringInterface& rhs) = 0;
};

class String : public StringInterface {
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
    const String &insert(const StringInterface &str, size_t pos) override;
    const String &append(const StringInterface &str) override;
    const String &prepend(const StringInterface &str) override;
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    StringInterface &operator=(const StringInterface &rhs) override;
    StringInterface &operator+(const StringInterface& rhs) override;
    static String fromInt(int value);
    String &operator=(const String &rhs);
};
