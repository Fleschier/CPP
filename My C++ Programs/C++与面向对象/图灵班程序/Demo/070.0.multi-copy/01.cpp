#include<iostream>
#include<iomanip>

using namespace std;

class A
{
public:
	void f_a() { cout<<"f_a"<<endl; }
};

class B : public A
{
public:
	void f_b() { cout<<"f_b"<<endl;}
};

class C : public A
{
public:
	void f_c() { cout<<"f_b"<<endl;};
};

class D : public B, public C
{
};


int main()
{
	D d;

	//d.f_a();

	return 0;
}
