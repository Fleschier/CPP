#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

    cout << "Jan = " << Jan << endl;
    cout << "Feb = " << Feb << endl;
    cout << "Mar = " << Mar << endl;
    cout << "Apr = " << Apr << endl;
    cout << "May = " << May << endl;
    cout << "Jun = " << Jun << endl;
    cout << "Jul = " << Jul << endl;
    cout << "Aug = " << Aug << endl;
    cout << "Sep = " << Sep << endl;
    cout << "Oct = " << Oct << endl;
    cout << "Nov = " << Nov << endl;
    cout << "Dec = " << Dec << endl;

    Month m;

    m = May;

    if ( 5 == m ) cout << "Yes." << endl;
    else cout << "No." << endl;

    return 0;
}
