#include<iostream>

using namespace std;

#define PI 3.14159

class circle
{
public:
    double radius;
    void set_r( double );
    double area();
};

double circle::area()
{
    return PI * radius * radius;
}

void circle::set_r( double r )
{
    radius = r;
}

int main()
{
    double r;
    circle c1;

    cout << "radius = ";
    cin >> r;
    c1.set_r( r );

    cout << "area = " << c1.area() << endl;

    return 0;
}