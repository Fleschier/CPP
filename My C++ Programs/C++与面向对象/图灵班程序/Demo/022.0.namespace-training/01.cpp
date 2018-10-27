#include<iostream>
#include<vector>
#include"name1.h"
#include"name2.h"
#include"name3.h"

using namespace std;
using namespace n1;
using namespace n2;
using namespace n3;

int main()
{
    vector<int> iv;
    double average;

    readvector( "a.txt", iv );
    throw_away( iv );
    average = ave( iv );

    cout << "average = " << average << endl;

    return 0;
}

