#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    char temp[] = "Hello";
    char temp2[] = "world";


    String s1{temp};
    String s2{temp2};
    String s3{s1};
    String s4{move(s2)};


    cout << endl << s1.toString() << endl;
    //cout << endl << s2.toString() << endl; //s2 is nullptr after move constructor
    cout << endl << s3.toString() << endl;
    cout << endl << s4.toString() << endl;


    s1 = s4;
    cout << endl << "copy test: " << s1 << endl;
    cout << endl << "s3 test: " << s3 << endl;

    cout << endl << "insert test: " << s1.insert(s3, 2) << endl;
    cout << endl << "s1 text: " << s1.toString() << endl;
    cout << endl << "s1 length: " << s1.length() << endl;

    return 0;
}
