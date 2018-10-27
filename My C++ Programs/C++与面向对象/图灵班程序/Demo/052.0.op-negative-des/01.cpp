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
    int  count;
    tracking tk;
public:
    counter( int i = 0 )
    {
        count = i;
    }
    void	clear()
    {
        count = 0;
    }
    void	kick()
    {
        count++;
    }
    int		tell()
    {
        return count;
    }
    counter operator - ();
    counter &operator = ( counter & );
};

counter counter::operator -()
{
    return counter( -count );
}

counter &counter::operator = ( counter &c )
{
    count = c.count;
    return *this;
}

int main()
{
    counter c1( 100 ), c2;

    cout << c1.tell() << endl;
    cout << c2.tell() << endl;
    cout << "---------------------1" << endl;

    c2 = -c1;

    cout << "---------------------2" << endl;
    cout << c1.tell() << endl;
    cout << c2.tell() << endl;

    return 0;
}