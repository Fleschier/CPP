#include<iostream>
#include<assert.h>

using namespace std;

int main()
{
    int a, b, c;

    a = 1;
    b = 0;
    
	assert( b != 0 );
	c = a / b;

    cout << "get here..." << endl;

    return 0;
}
