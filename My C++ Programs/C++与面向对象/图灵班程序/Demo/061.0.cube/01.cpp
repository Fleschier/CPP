#include<iostream>

using namespace std;

class rect
{
protected:
    double length, width;
public:
    rect() {}
    rect( double a, double b )
    {
        length = a;
        width = b;
    }
    void set( double a, double b )
    {
        length = a;
        width = b;
    }
    double getarea()
    {
        return length * width;
    }
};

class cube: public rect
{
protected:
    double height;
public:
    cube() {}
    cube( double a, double b, double c ): rect( a, b )
    {
        height = c;
    }
    void set( double a, double b, double c )
    {
        rect::set( a, b );
        height = c;
    }
    double getvolume()
    {
        return height * getarea();
    }
};

int main()
{
    rect r1( 1.0, 2.0 );
    cout << r1.getarea() << endl;

    cube c1( 1.0, 2.0, 3.0 );
    cout << c1.getvolume() << endl;

    cube c2;
    c2.set( 2.0, 3.0, 4.0 );
    cout << c2.getvolume() << endl;

    return 0;
}