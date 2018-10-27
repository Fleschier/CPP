#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{
    ifstream in( "a.txt" );
    int element;

    vector< vector<int> >  m;
    vector<int> line;

    for ( string s; getline( in, s );  )
    {
        line.clear();
        for ( istringstream sin( s ); sin >> element; line.push_back( element ) );
        m.push_back( line );
    }
    in.close();

    for ( unsigned int i = 0; i < m.size(); i++ )
    {
        for ( unsigned int j = 0; j < m[i].size(); j++ )
        {
            cout << setw( 5 ) << left << m[i][j];
        }
        cout << endl;
    }

    return 0;
}
