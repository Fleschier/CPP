#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

void display( int n, double d = 2 )
{
    cout << "int, double" << endl;
    return;
}

void display( int n )
{
    cout << "int" << n << endl;
    return;
}

int main()
{
    display( 1, 3 );
    //display(1);
    return 0;
}
