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
    vector<string> vstr;

    vstr.push_back( "aaa" );
    vstr.push_back( "aa" );
    vstr.push_back( "10bcd" );
    vstr.push_back( "zaa" );
    vstr.push_back( "caa" );

    sort( vstr.begin() + 1, vstr.end() - 1, less<string>() );

    for ( unsigned int i = 0; i < vstr.size(); i++ )
    {
        cout << vstr[i] << endl;
    }

    return 0;
}

