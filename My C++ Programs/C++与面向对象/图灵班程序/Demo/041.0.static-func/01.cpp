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
    static int num;
public:
    counter()
    {
        count = ++num;
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
    int  tell()
    {
        return count;
    }

    static int  report()
    {
        return num;
    }
};

int counter::num = 0;

int main()
{
    cout << "Current num = " << counter::report() << endl;
    counter c1[5];
    cout << "Current num = " << counter::report() << endl;

    return 0;
}