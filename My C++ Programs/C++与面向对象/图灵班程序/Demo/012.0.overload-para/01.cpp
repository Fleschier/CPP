#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

void display( long n )
{
    cout << "long" << endl;
    return;
}

void display( double d )
{
    cout << "double" << endl;
    return;
}

int main()
{
    int a = 1;
    double b = 2;

    //display( 0 );
    //display( a );
    display( b );

    return 0;
}

