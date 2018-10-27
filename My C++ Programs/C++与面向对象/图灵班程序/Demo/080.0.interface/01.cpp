#include<iostream>

using namespace std;

class A
{
public:
    virtual void a1() = 0;
    virtual void a2() = 0;
};

class B
{
public:
    virtual void b1() = 0;
    virtual void b2() = 0;
};

class C
{
public:
    virtual void c1() = 0;
    virtual void c2() = 0;
};

class D	: public A, public B
{
    int member1;
public:
    virtual void a1()
    {
        cout << "D_a1" << endl;
        return;
    }
    virtual void a2()
    {
        cout << "D_a2" << endl;
        return;
    }
    virtual void b1()
    {
        cout << "D_b1" << endl;
        return;
    }
    virtual void b2()
    {
        cout << "D_b2" << endl;
        return;
    }
};

class E	: public A, public C
{
    int member2;
public:
    virtual void a1()
    {
        cout << "E_a1" << endl;
        return;
    }
    virtual void a2()
    {
        cout << "E_a2" << endl;
        return;
    }
    virtual void c1()
    {
        cout << "E_c1" << endl;
        return;
    }
    virtual void c2()
    {
        cout << "E_c2" << endl;
        return;
    }
};

void f( A &a )
{
    a.a1();
    return;
}

int main()
{
    D d;
    E e;

    f( d );
    f( e );

    return 0;
}
