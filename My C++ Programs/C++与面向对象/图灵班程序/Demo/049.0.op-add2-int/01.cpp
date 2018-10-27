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
    int operator +( int x );
};

int counter::operator +( int x )
{
    return count + x;
}

int main()
{
    counter c1, c2;

    cout << c1.tell() << endl;
    cout << c1 + 5 << endl;
    //cout << c1 + 5 + c2 << endl;
    //cout << (c1 + 5 + c2).tell() << endl;

    return 0;
}