#include<iostream>

using namespace std;

class test0
{
protected:
    int a;
public:
    void set0()
    {
        a = 10;
    }
};
//*****************************************************************************
class test1: public test0
{
protected:
    int a;
public:
    void set0()
    {
        a = 20;
    }
    void print()
    {
        cout << "a = " << a << endl;
        cout << test0::a << endl;
    }
};

int main()
{
    test1 t;

    t.set0();
    //t.test0::set0();
    t.print();
    return 0;
}