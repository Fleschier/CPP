#include<iostream>

using namespace std;

class test0
{
private:
    int a0;
public:
    int c0;
    void set0( int i )
    {
        c0 = i;
    }
};

class test1 : public test0
{
private:
    int a1;
public:
    int c1;
    void set1( int i, int j )
    {
        c1 = i;
        set0( j );
    }
    void print()
    {
        cout << "c0 = " << c0 << endl;
        cout << "c1 = " << c1 << endl;
    }
};

int main()
{
    test1 t;

    t.set1( 10, 20 );
    t.print();

    t.set0( 10 );
    t.print();
    return 0;
}