#include<iostream>
#include<algorithm>
#include<functional>
#include"name2.h"

using namespace std;

namespace n2
{
    void throw_away( vector<int> &v )
    {
        sort( v.begin(), v.end(), greater<int>() );
        v.pop_back();
        v.pop_back();
        sort( v.begin(), v.end(), less<int>() );
        v.pop_back();
        v.pop_back();
        return;
    }
}
