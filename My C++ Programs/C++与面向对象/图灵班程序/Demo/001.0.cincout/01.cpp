#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int		i = 1;
    float	f = 2.3456F;
    double	d = 3.456789;

    cout << "i = " << i << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;

	cout << "Input i = ";
	cin  >> i;

    cout << "i = " << setw( 5 ) << i << endl;
    cout << "f = " << setw( 6 ) << setprecision( 3 ) << f << endl;
    cout << "d = " << setw( 10 ) << setprecision( 4 ) << left << d << "*" << endl;

    return 0;
}
