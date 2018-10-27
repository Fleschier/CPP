#include<iostream>

using namespace std;

template<typename T>
void my_swap( T &a, T &b )
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int ia, ib;
    double fa, fb;

    ia = 1;
    ib = 0;
    fa = 1.1;
    fb = 2.2;

    cout << "ia = " << ia << endl;
    cout << "ib = " << ib << endl;
    cout << "fa = " << fa << endl;
    cout << "fb = " << fb << endl;

    my_swap( ia, ib );
    my_swap( fa, fb );

    cout << endl;
    cout << "ia = " << ia << endl;
    cout << "ib = " << ib << endl;
    cout << "fa = " << fa << endl;
    cout << "fb = " << fb << endl;

    return 0;
}
