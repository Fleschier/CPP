#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main()
{
    int testint1 = 1;
    int &testref = testint1;

    cout << "testint1=" << testint1 << endl;
    cout << "testref=" << testref << endl;
    cout << "&testint1=" << &testint1 << endl;
    cout << "&testref=" << &testref << endl;
    cout << endl;

    int testint2 = 2;
    testref = testint2;

    cout << "testint1=" << testint1 << endl;
    cout << "testref=" << testref << endl;
    cout << "&testint2=" << &testint2 << endl;
    cout << "&testref=" << &testref << endl;

    return 0;
}

