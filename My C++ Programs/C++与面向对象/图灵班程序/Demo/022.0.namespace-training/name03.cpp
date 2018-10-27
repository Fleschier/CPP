#include <iostream>
#include "name3.h"

using namespace std;

namespace n3
{
    double ave( const vector<int> &v )
    {
        double sum = 0;
        if ( 0 == v.size() ) return 0.0;
        for( unsigned i = 0; i < v.size(); i++ )
        {
            sum += v[i];
        }
        return sum / v.size();
    }
}