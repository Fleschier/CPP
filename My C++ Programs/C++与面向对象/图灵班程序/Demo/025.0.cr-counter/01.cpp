#include<iostream>
#include"01.h"
using namespace std;
using namespace userdefined;

int main()
{
    cr_counter c1;

    c1.init( 5 );

    for ( int i = 0; i < 50; i++ )
    {
        cout << i << '\t';
        c1.cr();
    }
    cout << endl;
    return 0;
}