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
    //tracking tk;
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
    counter &operator = ( counter &c )
    {
        count = c.count;
        return *this;
    }
    counter &operator ++ ();	//	++c
    counter operator ++( int );	//	c++
    friend ostream &operator << ( ostream &os, counter &c );
};

ostream & operator << ( ostream &os, counter &c )
{
    os << c.tell() << endl;
    return os;
}

counter &counter::operator ++ ()
{
    ++count;
    return *this;
}

counter counter::operator ++ ( int )
{
    count++;
    return counter( count - 1 );
}

int main()
{
    counter c1( 100 ), c2;

    cout << c1 << c2;
    cout << "---------------------1" << endl;

    c2 = c1++;

    cout << "---------------------2" << endl;
    cout << c1 << c2;
    cout << "---------------------3" << endl;

    c2 = ++c1;

    cout << "---------------------4" << endl;
    cout << c1 << c2;

    return 0;
}