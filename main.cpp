#include <iostream>
#include <memory>
#include "mystring.h"

using namespace std;

int main()
{
    char temp[] = "Hello";
    char temp2[] = "world";

    //String s1{temp};
    unique_ptr<IString> s1 = make_unique<String>(temp);    
    String s2{temp2};
    String s3{s2};
    String s4{move(s2)};
    String s5{temp};
    String s6{temp2};

    cout << endl << s1->toString() << endl;
    //cout << endl << s2.toString() << endl; //s2 is nullptr after move constructor
    cout << endl << s3.toString() << endl;
    cout << endl << s4.toString() << endl;
    
    s1 = make_unique<String>(s4); 
    cout << endl << "copy test: " << *s1 << endl;
    cout << endl << "s3 test: " << s3 << endl;

    cout << endl << "insert test: " << s1->insert(s3, 2)<< endl;
    cout << endl << "s1 text: " << s1->toString() << endl;
    cout << endl << "s1 length: " << s1->length() << endl;

    cout << endl << "s1 append s3: " << s1->append(s3) << endl;
    cout << endl << "s1: " << *s1 << endl;
    cout << endl << "s1 length: " << s1->length() << endl;

    cout << endl << "s6 prepend s5: " << s6.prepend(s5) << endl;
    cout << endl << "s6: " << s6 << endl;
    cout << endl << "s6 length: " << s6.length() << endl;

    cout << endl << "s5: " << s5 << endl;
    cout << endl << "s5 length: " << s5.length() << endl;
    s5 = s5 + s5;
    cout << endl << "s5: " << s5 << endl;
    cout << endl << "s5 length: " << s5.length() << endl;
    
    cout << endl << "fromInt: " << String::fromInt(2147483647).length() << endl;

    return 0;
}
