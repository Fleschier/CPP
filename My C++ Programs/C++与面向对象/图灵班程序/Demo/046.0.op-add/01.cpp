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
    counter( counter &r )
    {
		count = r.count;
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
    counter plus( counter & );
};

counter counter::plus( counter &c )
{
    return counter( count + c.count );
}

int main()
{
    counter c1( 100 ), c2(5), c3;

    cout << "Current counter3 = " << c3.tell() << endl;
    c3 = c2.plus( c1 );
    cout << "Current counter3 = " << c3.tell() << endl;

    return 0;
}