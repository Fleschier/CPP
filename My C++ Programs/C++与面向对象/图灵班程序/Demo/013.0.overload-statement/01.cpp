#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

void display( int n )
{
    cout << n << endl;
    return;
}

int display( int n )
{
    cout << n << endl;
    return n;
}

int main()
{
    int x;

    x = display( 0 );
    return 0;
}

