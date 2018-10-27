#include<iostream>
#include<exception>
#include<string>

using namespace std;

int main()
{
    int a, b, c;

    a = 1;
    b = 0;
    //c = a / b;
    
    try
    {
    	c = a / b;
    }
    catch(...)
    {
    	cout<<"errors!"<<endl;
    }
    
    cout << "get here..." << endl;

    return 0;
}
