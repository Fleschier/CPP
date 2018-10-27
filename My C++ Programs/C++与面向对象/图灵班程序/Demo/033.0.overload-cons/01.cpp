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
    counter c1;
    counter c2( 100 );

    cout << "Current counter = " << c1.tell() << endl;
    cout << "Current counter = " << c2.tell() << endl;

    return 0;
}