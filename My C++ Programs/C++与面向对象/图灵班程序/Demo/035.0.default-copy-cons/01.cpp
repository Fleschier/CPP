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
    counter();
    counter( int );
    void clear();
    void kick();
    int  tell();
};

counter::counter()
{
    count = 0;
}

counter::counter( int i )
{
    count = i;
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

int counter::tell()
{
    return count;
}

int main()
{
    counter c1, c2( 100 ), c3( c2 ), c4;

    //c4 = c2;
    cout << "Current counter = " << c1.tell() << endl;
    cout << "Current counter = " << c2.tell() << endl;
    cout << "Current counter = " << c3.tell() << endl;
    cout << "Current counter = " << c4.tell() << endl;

    return 0;
}
