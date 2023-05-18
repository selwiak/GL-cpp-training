#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    String s1;

    char temp[] = "Hello";

    String s2{temp};

    cout << endl << s1.toString() << endl;
    cout << endl << s2.toString() << endl;

    cout<<s2;
    
    return 0;
}
