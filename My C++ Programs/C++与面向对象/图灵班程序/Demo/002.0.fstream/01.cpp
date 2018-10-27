#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream in( "a.txt" );
    ofstream out( "b.txt" );
    string str;

    while( getline( in, str ) )
    {
        out << str << endl;
        cout << str << endl;
    }

    cout << "Done." << endl;

    return 0;
}
