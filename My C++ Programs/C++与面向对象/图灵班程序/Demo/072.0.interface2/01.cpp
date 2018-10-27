#include<iostream>
#include<iomanip>

using namespace std;

class area
{
public:
	double virtual get_area() = 0;
};

class volume
{
public:
	double virtual get_volume() = 0;
};

class circle : public area
{
	double r;
public:
	circle(double x) { r = x;}
	double virtual get_area() { return 3.14*r*r; }
	double length() { return 2*3.14*r; }
};

class column : public circle, public volume
{
	double height;
public:
	column(double x, double y) : circle(y), height(x) {}
	double virtual get_area() { return length()*height+2*circle::get_area(); }
	double virtual get_volume() { return circle::get_area()*height; }
};

class cube : public area, public volume
{
	double length, width, height;
public:
	cube(double x, double y, double z) : length(x), width(y), height(z) {}
	double virtual get_area() { return (length*height+length*width+width*height)*2; }
	double virtual get_volume() { return length*width*height; }
};

void print_area( area & a)
{
	cout<< a.get_area() << endl;
}

void print_volume( volume & v )
{
	cout<< v.get_volume() << endl;
}

int main()
{
	circle cir( 1 );
	column col( 1, 2);
	cube cub( 1, 2, 3 );

	print_area( cir );
	print_volume( col );
	
	print_area( cub );
	print_volume( cub );

	return 0;
}
