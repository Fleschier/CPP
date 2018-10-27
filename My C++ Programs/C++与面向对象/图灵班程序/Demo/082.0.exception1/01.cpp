#include<iostream>
#include<exception>
#include<string>

using namespace std;

int main()
{
    int c[10];

    //c[1000] = 0;

    try
    {
    	c[1000] = 0;
    }
    catch(...)
    {
    	cout<<"errors!"<<endl;
    	return 0;
    }

    cout << "ok." << endl;
    return 0;
}
