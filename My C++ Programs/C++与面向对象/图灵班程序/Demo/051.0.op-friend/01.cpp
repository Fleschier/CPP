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
    friend counter operator +( counter &, counter & );
};

counter operator +( counter &a, counter &b )
{
    return counter( a.count + b.count );
}

int main()
{
    counter c1( 100 ), c2( 200 ), c3;

    cout << "Current counter = " << c1.tell() << endl;
    cout << "Current counter = " << c2.tell() << endl;
    cout << "Current counter = " << c3.tell() << endl;

    c3 = c1 + c2;

    cout << "Current counter = " << c3.tell() << endl;
    cout << "Current counter = " << ( c1 + c2 ).tell() << endl;

    return 0;
}