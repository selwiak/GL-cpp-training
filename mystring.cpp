#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

String::String()
{
    text = nullptr;
    cout << "Object created." << endl;
}

String::String(char *str)
{
    // check if there initial value is given
    if(str == nullptr)
    {
        // no initial value, create empty object
        text = nullptr;
    }
    else
    {
        // initial value given, copy it to string
        size = strlen(str) + 1;
        text = make_unique<char[]>(size);
        //text = make_unique<char[]>(strlen(str) + 1);
        strcpy(text.get(), str);
        text[size] = '\0';

        cout << "Created object: " << text.get() << endl;
    }
}

//copy constructor
String::String(const String &str)
{
    if(&str != nullptr)
    {
        // get length of original string
        size = str.length();
        text = make_unique<char[]>(size);
        // copy original string
        strcpy(text.get(), str.text.get());

        cout << "Object copied: " << text.get() << endl;
    }
    else
    {
        //
    }
}

//move constructor
String::String(String &&str) : text(std::move(str.text)) {
    size = str.size;
    str.text = nullptr;
}

String::~String(){}

const char *String::toString() const
{  
    return text.get();
}

ostream & operator<<(ostream& os, const String &s) 
{  
    return os << s.text.get() << endl;
}

unsigned int String::length() const
{  
    return size;
}

//function which insert substring in specified position
const String & String::insert(const IString &otherStr, size_t pos)
{
    //check if given position is inside object string
    if((pos < (length())) && (pos > 0))
    {   
        // cast IString to String
        const String& str = static_cast<const String&>(otherStr);

        //start from given position and replace characters till end of the string
        for(int i = pos, j = 0; i <= (length()); i++,j++)
        {
            text[i+(str.length()-1)] = text[i];
            text[i] = str.text[j];
        }
        //update size of current object, -1 to remove one '/0'
        size = length() + (str.length() - 1);
    }

    return *this;
}

//function which append strings
const String & String::append(const IString &str) 
{
    // cast IString to String
    const String& obj = static_cast<const String&>(str);

    //go to end of object string(ignore '/0' at end of object) and add new chars to it
    for(int i = (length() - 1), j = 0; i < (length() + str.length() -2); i++, j++)
    {
        text[i] = obj.text[j];
    }

    //update size of current object, -1 to remove one '/0'
    size = size + (str.length() - 1);
    
    return *this;
}

//function which prepend string
const String & String::prepend(const IString &str) 
{
    // cast IString to String
    const String& obj = static_cast<const String&>(str);

    //move current object to the left to create space for a new string
    for(int i = (length() + (str.length() - 1)), j = length(); i > 0; i--,j--)
    {
        text[i] = text[j]; 
    }

    //copy new string to created space
    for(int i = 0; i < (str.length() - 1); i++)
    {
        text[i] = obj.text[i];
    }

    //update size of current object, -1 to remove one '/0'
    size = length() + (str.length() - 1);
    
    return *this;
}

//function which convert int to String object
String String::fromInt(int value)
{   
    //variable to store int length
    int length = 0;
    //variable to copy int value
    int temp = value;

    //check if value is negative, if it is replace temp with positive
    if(temp < 0)
    {
        temp = -temp;
        length++;
    }

    //get length of int
    while(temp > 0) 
    {
        temp = temp/10;
        length++;
    }
    
    //create char arraty to store converted int
    char text[length];

    //add minus at the beginning if value is negative
    if(value < 0)
    {
        text[0] = '-';
        value = -value;
    }

    //add '\0' at the end, and decrease length 
    text[length] = '\0';
    length--;

    while(value > 0) 
    {
        text[length] = '0' + (value % 10);
        value = value/10;
        length--;
    }

    //create object to return
    String string{text};

    return string;
}

//overloading assigment operator
String & String::operator=(const String &obj)
{
    //guard self assignment
    if(this != &obj)
    {
        size = obj.size;
        strncpy(text.get(), obj.text.get(), obj.length());
    }

    return *this;
}

//overloading assigment operator
IString & String::operator=(const IString &obj)
{
    //guard self assignment
    if(this != &obj)
    {
        // cast StringInterface to String
        const String& obj = static_cast<const String&>(obj);

        size = obj.size;
        strncpy(text.get(), obj.text.get(), obj.length());
    }

    return *this;
}

//overloading plus operator
IString & String::operator+(const IString &obj)
{
    append(obj);

    return *this;
}