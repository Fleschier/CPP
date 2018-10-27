#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

class test1
{
public:
    test1();
    ~test1();
};

test1::test1()
{
    cout << "con.test1" << endl;
}

test1::~test1()
{
    cout << "des.test1" << endl;
}

class test2
{
    test1 obj;
public:
    test2();
    ~test2();
};

test2::test2()
{
    cout << "con.test2" << endl;
}

test2::~test2()
{
    cout << "des.test2" << endl;
}

int main()
{
    test2 t2;

    return 0;
}