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
    int  no;
public:
    static int sum;
public:
    counter()
    {
        no = ++sum;
    }
    void clear()
    {
        count = 0;
        return;
    }
    void kick()
    {
        count++;
        return;
    }
    int  tellc()
    {
        return count;
    }
    int  telln()
    {
        return no;
    }
    int  tells()
    {
        return sum;
    }
};

int counter::sum = 0;

int main()
{
    cout << "Current num = " << counter::sum << endl;
    counter c1[5];

    for ( int i = 0; i < 5; i++ )
    {
        cout << c1[i].telln() << "\t" << c1[i].tells() << endl;
    }
    cout << "Current num = " << counter::sum << endl;

    return 0;
}