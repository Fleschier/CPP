#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

class counter
{
    int  count;
public:
    void clear();
    void kick();
    void kick_back();
    int  tell();
    friend int tellcount( const counter & );
};

int tellcount( const counter &c )
{
    return c.count;
}

void counter::clear()
{
    count = 0;
    return;
}

void counter::kick()
{
    count++;
    return;
}

void counter::kick_back()
{
    if ( count ) count--;
    return;
}

int counter::tell()
{
    return count;
}

int main()
{
    counter c1;

    c1.clear();
    cout << "Current counter = " << c1.tell() << endl;

    c1.kick();
    cout << "Current counter = " << tellcount( c1 ) << endl;

    return 0;
}