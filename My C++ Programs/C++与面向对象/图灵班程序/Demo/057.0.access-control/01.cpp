#include<iostream>
using namespace std;

class test0
{
private:
    int a0;
protected:
    int b0;
public:
    int c0;
    void set0()
    {
        a0 = 0;
        b0 = 0;
        c0 = 0;
    }
};

class test1 : public test0
{
private:
    int a1;
protected:
    int b1;
public:
    int c1;
    void set1();
};


void test1::set1()
{
    a1 = 0;
    b1 = 0;
    c1 = 0;

    a0 = 0;
    b0 = 0;		//???
    c0 = 0;
}

int main()
{
    test1 t;

    t.a0 = 0;
    t.b0 = 0;
    t.c0 = 0;

    t.a1 = 0;
    t.b1 = 0;
    t.c1 = 0;

    t.set0();
    t.set1();

    return 0;
}