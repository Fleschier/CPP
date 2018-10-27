#include<iostream>

using namespace std;

class test0
{
protected:
    int a;
public:
    test0()
    {
        cout << "test0 constructor" << endl;
    }
    ~test0()
    {
        cout << "test0 destructor" << endl;
    }
    test0( int n )
    {
        a = n;
    }
};

class test1 : public test0
{
    int aa;
public:
    test1()
    {
        cout << "test1 constructor" << endl;
    }
    ~test1()
    {
        cout << "test1 destructor" << endl;
    }
};

class test2: public test1
{
    int aaa;
public:
    test2()
    {
        cout << "test2 constructor" << endl;
    }
    ~test2()
    {
        cout << "test2 destructor" << endl;
    }
};


int main()
{
    test2 t;

    return 0;
}