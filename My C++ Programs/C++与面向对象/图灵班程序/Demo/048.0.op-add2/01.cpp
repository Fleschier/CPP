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
    counter operator +( counter & );
    counter operator +( int i );
};

counter counter::operator +( counter &c )
{
    return counter( count + c.count );
}

counter counter::operator +( int i )
{
    return counter( count + i );
}

int main()
{
    counter c1( 100 ), c2( 200 ), c3;

    cout << "Current counter1 = " << c1.tell() << endl;
    cout << "Current counter2 = " << c2.tell() << endl;
    cout << "Current counter3 = " << c3.tell() << endl;

    c3 = c1 + c2 + 3;
    //c3 = c1 + 3 + c2;

    cout << "Current counter1 = " << c1.tell() << endl;
    cout << "Current counter2 = " << c2.tell() << endl;
    cout << "Current counter3 = " << c3.tell() << endl;
    cout << "Current counter  = " << ( c1 + 5 ).tell() << endl;

    return 0;
}