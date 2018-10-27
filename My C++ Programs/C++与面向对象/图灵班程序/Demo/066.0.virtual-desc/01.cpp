#include<iostream>

using namespace std;

class A1
{
protected:
    int a;
public:
    A1()
    {
        cout << "A1 constructor" << endl;
    }
    virtual ~A1()
    {
        cout << "A1 destructor" << endl;
    }
};

class A2: public A1
{
    int aa;
public:
    A2()
    {
        cout << "A2 constructor" << endl;
    }
    virtual ~A2()
    {
        cout << "A2 destructor" << endl;
    }
};

class A3: public A2
{
    int aaa;
public:
    A3()
    {
        cout << "A3 constructor" << endl;
    }
    virtual ~A3()
    {
        cout << "A3 destructor" << endl;
    }
};

void f( A1 *a )
{
    delete a;
    return;
}

int main()
{
    A3 *a3 = new A3;

    f( a3 );

    return 0;

}