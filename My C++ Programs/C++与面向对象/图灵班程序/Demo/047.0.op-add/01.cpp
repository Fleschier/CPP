#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

#include"02.cpp"

class counter
{
    tracking tk;
    int  count;
public:
    counter( int i = 0 )
    {
        count = i;
    }
    void clear()
    {
        count = 0;
    }
    void kick()
    {
        count++;
    }
    int  tell()
    {
        return count;
    }
    counter operator +( counter & );
};

counter counter::operator +( counter &c )
{
    return counter( count + c.count );
}

int main()
{
    counter c1( 100 ), c2( 200 ), c3;

    cout << "Current counter1 = " << c1.tell() << endl;
    cout << "Current counter2 = " << c2.tell() << endl;
    cout << "Current counter3 = " << c3.tell() << endl;

    c3 = c1 + c2;
    cout << "Current counter3 = " << c3.tell() << endl;

    cout << "Current counterX = " << ( c1 + c3 ).tell() << endl;

    return 0;
}