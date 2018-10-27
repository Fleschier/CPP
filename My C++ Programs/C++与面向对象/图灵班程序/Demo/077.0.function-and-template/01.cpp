#include<iostream>

using namespace std;

template<typename T>
T divi( T &a, T &b )
{
    return a / b;
}

int divi( int &a, int &b )
{
    return a + b;
}

int divi<>( int &a, int &b )
{
    return a * b;
}

int main()
{
    int ia, ib;
    float fa, fb;

    ia = 1;
    ib = 3;
    fa = 1;
    fb = 3;

    cout << "ia/ib = " << divi( ia, ib ) << endl;
    cout << "fa/fb = " << divi( fa, fb ) << endl;

    return 0;
}
