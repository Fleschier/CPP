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
    counter & operator =( counter & );
};

counter counter::operator +( counter & c  )
{
	return counter(count + c.count);
}

counter & counter::operator = ( counter & c )
{
	count = c.count;
    return *this;
}

int main()
{
    counter c1(5), c2(10), c3;

    cout << "c1 = " << c1.tell() << endl;
    cout << "c2 = " << c2.tell() << endl;

	c3 = c1 + c2;
    cout << "c3 = " << c3.tell() << endl;

	int i;

	(i = 3)++;
	cout << i << endl;
    return 0;
}