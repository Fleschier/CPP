#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<time.h>
#include<functional>
#include<algorithm>

using namespace std;

void display( const vector<int> &v )
{
    for ( unsigned int i = 0; i < v.size(); i++ )
    {
        cout << v[i] << endl;
    }
    return;
}

int main()
{
    int aa[] = { 100, 45, 97, 2, 13, 4, 5, 6 };
    vector<int> a( aa, aa + sizeof( aa ) / sizeof( int ) );
    vector<int> b( aa, aa + sizeof( aa ) / sizeof( int ) );

    sort( a.begin(), a.end(), less<int>() );
    display( a );

    sort( b.begin(), b.end(), greater<int>() );
    display( b );

    return 0;
}

