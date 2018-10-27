#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

int main()
{
    int i = 0, j = 0;

    //j = ++(++i);
    //j = (++i)++;
    //j = (++(++i))+(++(++i));
    j = ((++i)++)+((++i)++);
    //j = (i++)++;
    //j = ++(i++);

    cout << "i=" << i << ",j=" << j << endl;
    return 0;

}