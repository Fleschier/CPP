#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

void display( int n )
{
    cout << "int" << endl;
    return;
}

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

void display( float d )
{
    cout << "float" << endl;
    return;
}

int main()
{
    int a = 1;
    long b = 1;
    float c = 1;
    double d = 2;

    display( a );
    display( b );
    display( c );
    display( d );

    return 0;
}
