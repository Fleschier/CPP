#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{
    string a, b, c;

    a = "hello ";
    b = "world.";
    c = a + b;
    cout << c << endl;

    if ( c.find( "hee" ) == -1 )
    {
        cout << "not found" << endl;
    }
    cout << c.find( "he" ) << endl;

    reverse( c.begin(), c.end() );
    cout << c << endl;

    c.replace( c.begin(), c.end() - 6, 8, 'a' );
    cout << c << endl;

    return 0;
}
