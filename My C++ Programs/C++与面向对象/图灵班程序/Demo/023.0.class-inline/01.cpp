#include<iostream>

using namespace std;

class counter
{
    int count;
public:
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

    void kick_back()
    {
        if ( count ) count--;
        return;
    }

    int tell()
    {
        return count;
    }
};

int main()
{
    counter c1;

    c1.clear();
    c1.kick();
    c1.kick();
    cout << "Current counter = " << c1.tell() << endl;
    c1.kick_back();
    c1.kick_back();
    c1.kick_back();
    cout << "Current counter = " << c1.tell() << endl;

    return 0;
}