#include<iostream>
#include<exception>
#include<string>
#include<assert.h>
using namespace std;

int main()
{
    int *b;

    //delete b;
    
	b = new int;
	delete b;

    try
    {
    	delete b;
    }
    catch(...)
    {
    	cout<<"errors"<<endl;
    }
    
    return 0;
}
