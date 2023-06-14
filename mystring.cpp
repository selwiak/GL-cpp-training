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

ostream & operator<< (ostream& os, const String &s) 
{
   return os << s.text.get() << endl;
}

unsigned int String::length() const
{  
    return size;
}

//overloading assigment operator
String & String::operator=(const String &obj)
{
    //guard self assignment
    if(this != &obj)
    {
        size = obj.size;
        strcpy(text.get(), obj.text.get());
    }

    return *this;
}

//function which insert substring in specified position
const char *String::insert(const String &str, size_t pos)
{
    char *result = nullptr;

    //check if given position is inside object string
    if((pos < (this->length())) && (pos > 0))
    {   
        //start from given position and replace characters till end of the string
        for(int i = pos, j = 0; i <= (this->length()); i++,j++)
        {
            this->text[i+(str.length()-1)] = this->text[i];
            this->text[i] = str.text[j];
        }
        //update size of current object, -1 to remove one '/0'
        this->size = this->length() + (str.length() - 1);

        result = text.get();
    }

    return result;
}

//function which append strings
const char *String::append(const String &str) 
{
    //go to end of object string(ignore '/0' at end of object) and add new chars to it
    for(int i = (this->length() - 1), j = 0; i < (this->length() + str.length()); i++, j++)
    {
        this->text[i] = str.text[j];
    }

    //update size of current object, -1 to remove one '/0'
    this->size = this->size + (str.length() - 1);
    
    return text.get();
}

//function which prepend string
const char *String::prepend(const String &str) 
{
    //move current object to the left to create space for a new string
    for(int i = (this->length() + (str.length() - 1)), j = this->length(); i > 0; i--,j--)
    {
        this->text[i] = this->text[j]; 
    }

    //copy new string to created space
    for(int i = 0; i < (str.length() - 1); i++)
    {
        this->text[i] = str.text[i];
    }

    //update size of current object, -1 to remove one '/0'
    this->size = this->length() + (str.length() - 1);
    
    return text.get();
}