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
    virtual void show() { }
    //virtual void show()=0;
};

class B	: public A
{
    int num;
public:
    B()
    {
        num = 2;
    }
    virtual void show()
    {
        cout << "The num of B is " << num << endl;
    }
};

class C	: public B
{
    int num;
public:
    C()
    {
        num = 3;
    }
    void virtual show()
    {
        cout << "The num of C is " << num << endl;
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
    C c;

    test( a );
    test( b );
    test( c );

    return 0;
}
