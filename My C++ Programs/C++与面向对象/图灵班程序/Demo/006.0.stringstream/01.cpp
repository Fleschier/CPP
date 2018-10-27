#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    ifstream in( "a.txt" );
    ofstream out( "b.txt" );
    string line;
    int element, sum;

    while( getline( in, line ) )
    {
        sum = 0;
		
		/*
		istringstream sin( line );
        while ( sin >> element )
        {
            sum += element;
        }
        delete sin;
		*/
		
        for (istringstream sin(line); sin>>element; sum += element);
        out << line << sum << endl;
        cout << line << sum << endl;
    }
    in.close();
    out.close();

    return 0;
}
