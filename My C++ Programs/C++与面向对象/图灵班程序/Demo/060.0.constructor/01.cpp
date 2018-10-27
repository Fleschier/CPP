#include<iostream>

using namespace std;

class test0
{
protected:
    int a0;
public:
    test0()
    {
        a0 = 0;
    }
    test0( int n )
    {
        a0 = n;
    }
    void print()
    {
        cout << "a0=" << a0 << endl;
    }
};

class test1 : public test0
{
    int a1;
public:
    test1()
    {
        a1 = 0;
    }
    test1( int n, int m, int k ): test0( m + k )
    {
        a1 = k - n;
    }
    //test1(int n, int m, int k) { a1 = k-n; }
    void print()
    {
        cout << "a1=" << a1 << endl;
        test0::print();
    }
};

int main()
{
    test1 t1, t2( 1, 2, 0 );

    t1.print();
    t2.print();
    return 0;
}