#include<iostream>

using namespace std;

class A
{
    int num;
public:
    A()
    {
        num = 1;
    }
    void virtual show()
    {
        cout << "The num of A is " << num << endl;
    }
};


class B	: public A
{
    int num;
public:
    B()
    {
        num = 2;
    }
    void virtual show()
    {
        cout << "The num of B is " << num << endl;
    }
};

void test( A &ra )
{
    ra.show();
}

int main()
{
    A a;
    B b;

    test(a);
    test( b );

    return 0;
}
