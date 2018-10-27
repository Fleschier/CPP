#include<iostream>

using namespace std;

class counter
{
public:
    int  count;
    void clear();
    void kick();
    void kick_back();
    int  tell();
};

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

void counter::kick_back()
{
    if ( count ) count--;
    return;
}

int counter::tell()
{
    return count;
}


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