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
    virtual void show()
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
    void show()
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
    void show()
    {
        cout << "The num of C is " << num << endl;
    }
};

class D	: public C
{
    int num;
public:
    D()
    {
        num = 4;
    }
    void show()
    {
        cout << "The num of D is " << num << endl;
    }
};

void test( B &r )
{
    r.show();
}

int main()
{
    A a;
    B b;
    C c;
    D d;

    //test( a );
    test( b );
    test( c );
    test( d );

    return 0;
}
