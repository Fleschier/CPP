#include<iostream>

using namespace std;

template<typename T>
T divi( T &a, T &b )
{
    return a / b;
}

template<typename T>
T divis( T a, T b )
{
    return a / b;
}

int main()
{
    int ia, ib;
    float fa, fb;

    ia = 1;
    ib = 3;
    fa = 1;
    fb = 3;

    cout << "ia/fb = " << divis( ia, fb ) << endl;
    cout << "ia/fb = " << divi ( ia, fb ) << endl;

    cout << "ia/fb = " << divi<double>( ia, fb ) << endl;
    cout << "ia/fb = " << divis<double>( ia, fb ) << endl;

    return 0;
}
