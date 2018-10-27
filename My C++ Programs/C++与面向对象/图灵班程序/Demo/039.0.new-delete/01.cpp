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
    cout << "I am coming!" << endl;
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
    counter *c1;

    c1 = new counter;

    cout << "Current counter = " << ( *c1 ).tell() << endl;

    delete c1;
    c1 = NULL;

    return 0;
}