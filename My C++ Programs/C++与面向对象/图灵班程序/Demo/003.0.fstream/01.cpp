#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream in( "a.txt" );
    ofstream out1( "b.txt" );
    ofstream out2( "c.bin", ios::binary );
    int temp;

    while( in >> temp )
    {
        out1 << temp << endl;
        out2.write( &temp, sizeof( int ) );
    }

    cout << "Done." << endl;

    return 0;
}
