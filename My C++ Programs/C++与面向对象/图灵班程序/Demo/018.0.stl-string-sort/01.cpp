#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include<deque>
#include<functional>

using namespace std;

int main()
{
    string str;

    str = "hello";

    sort( str.begin(), str.end(), less<char>() );

    cout << str << endl;

    return 0;
}

