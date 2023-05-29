#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    char temp[] = "Hello";
    char temp2[] = "world";


    String s1{temp};
    String s2{temp2};

    cout << endl << s1.toString() << endl;
    cout << endl << s2.toString() << endl;
    
    return 0;
}
