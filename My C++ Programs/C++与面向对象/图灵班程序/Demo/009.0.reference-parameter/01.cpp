#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

void swap( int &a, int &b )
{
    int temp;

    temp = a;
    a = b;
    b = temp;
    return;
}

int & test( int &a )
{
	a++;
	return a;
}

int main()
{
    int aa, bb;

    aa = 1;
    bb = 2;

    cout << "aa=" << aa << endl;
    cout << "bb=" << bb << endl;
    swap( aa, bb );
    cout << "aa=" << aa << endl;
    cout << "bb=" << bb << endl;

    test( aa ) = 100;
    cout << "aa=" << aa << endl;

    return 0;
}

