#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

class counter
{
    int count;
public:
    counter( int i = 0 )
    {
        count = i;
    }
    void kick()
    {
        count = count++;
    }
    int &tell()
    {
        return count;
    }
};

int main()
{
    counter c1( 10 );

    c1.kick();
    cout << c1.tell() << endl;

    c1.tell() = 5;

    cout << c1.tell() << endl;

    return 0;
}
