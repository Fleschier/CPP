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
    counter &operator = ( counter &c )
    {
        count = c.count;
        return *this;
    }
    counter & operator ++ ();	//	++c
    counter operator ++( int );	//	c++
};

counter & counter::operator ++ ()
{
    ++count;
    return *this;
}

counter counter::operator ++ ( int )
{
    count++;
    return counter( count - 1 );
}

void f1()
{
    counter c1( 100 ), c2;

    cout << c1.tell() << endl;
    cout << c2.tell() << endl;

    cout << "---------------------1" << endl;
    c2 = c1++;
    cout << "---------------------2" << endl;

    cout << c1.tell() << endl;
    cout << c2.tell() << endl;

    cout << "---------------------3" << endl;
    c2 = ++c1;
    cout << "---------------------4" << endl;

    cout << c1.tell() << endl;
    cout << c2.tell() << endl;

    return ;
}

void f2()
{
    counter c1( 100 ), c2, *p;

    p = &c1;
    cout << ( int )p << endl;
    p = &( c1++ );
    cout << ( int )p << endl;
    p = &( ++c1 );
    cout << ( int )p << endl;

    return ;
}

int main()
{
    f1();
    //f2();
    return 0;
}