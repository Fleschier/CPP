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
    counter();
    ~counter();
    void clear();
    void kick();
    int  tell();
};

counter::counter()
{
    count = 0;
}

counter::~counter()
{
    cout << "I am leaving!" << endl;
}

void counter::clear()
{
    count = 0;
    return;
}

void counter::kick()
{
    count++;
    return;
}

int counter::tell()
{
    return count;
}


int main()
{
    counter c1;

    cout << "Current counter = " << c1.tell() << endl;

    return 0;
}