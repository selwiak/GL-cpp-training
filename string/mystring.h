#include <iostream>
#include <memory>
#include "string.h"

namespace str
{
    class String : public string {
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
        const String &insert(const string &str, size_t pos) override;
        const String &append(const string &str) override;
        const String &prepend(const string &str) override;
        String &operator=(const string &rhs) override;
        String &operator+(const string& rhs) override;
        static String fromInt(int value);
        String &operator=(const String &rhs);
        void print(std::ostream &os) const override;
    };
}
