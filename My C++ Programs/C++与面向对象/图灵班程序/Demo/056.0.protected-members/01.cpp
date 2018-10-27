#include<iostream>

using namespace std;

class test
{
private:
    int a;
protected:
    int b;
public:
    int c;
    void set()
    {
        a = 0;
        b = 0;
        c = 0;
    }
};

int main()
{
    test t;

    //t.a = 0;		//error
    //t.b = 0;		//error
    t.c = 0;
    return 0;
}