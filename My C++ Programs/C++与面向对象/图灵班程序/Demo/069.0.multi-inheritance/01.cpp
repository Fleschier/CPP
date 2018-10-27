#include<iostream>
#include<iomanip>

using namespace std;

class A
{
public:
	void f_a() { cout<<"f_a"<<endl;}
};

class B
{
public:
	void f_b() { cout<<"f_b"<<endl;}
};

class C : public A, public B
{
public:
	void f_c() { cout<<"f_c"<<endl;}
};

int main()
{
	C c;

	c.f_a();
	c.f_b();
	c.f_c();

    return 0;
}
