#include<iostream>

using namespace std;

template<typename T>
class divi
{
    T a;
    T b;
public:
    divi( T aa, T bb )
    {
        a = aa;
        b = bb;
    }
    T cal()
    {
        return a / b;
    }
    void disp()
    {
        cout << cal() << endl;
    }
};


int main()
{
    divi<int> x( 100, 12 );
    divi<double> y( 100, 12 );

    x.disp();
    y.disp();

    return 0;
}
