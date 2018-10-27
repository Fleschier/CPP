#include <iostream>
#include <fstream>
#include "name1.h"

using namespace std;

namespace n1
{
    void readvector( string fn, vector<int> &v )
    {
        ifstream fin( fn.c_str() );
        for( int i; fin >> i; )
        {
            v.push_back( i );
        }
        return;
    }
}