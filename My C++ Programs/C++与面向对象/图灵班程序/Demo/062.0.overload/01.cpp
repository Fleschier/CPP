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
    void show()
    {
        cout << "**********" << endl;
    }
    void show( int i, int j )
    {
        cout << "##########" << endl;
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
        cout << "++++++++++" << endl;
    }
    void show( int i )
    {
        cout << "==========" << endl;
    }
};

int main()
{
    A a;
    B b;

    a.show();
    a.show( 1, 1 );
    //a.show(1);

    b.show();
    b.show( 1 );
    b.A::show();
    b.A::show( 1, 1 );
    //b.show(1,1);

    return 0;
}
