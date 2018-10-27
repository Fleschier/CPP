#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void printOut(int n);
void printOut(double m);
void printOut(string str);

int main()
{
	int n; double m; string str;
	cout << "please enter an integer:\n";
	cin >> n;
	cout << "please enter a float:\n";
	cin >> m;
	cout << "please enter a string :\n";
	cin >> str;
	printOut(n);
	printOut(m);
	printOut(str);
	return 0;
}
//�������غ���--------------------------------------------
void printOut(int n) {
	cout << setw(10) << right << n << endl;
}

void printOut(double m) {
	cout <<fixed<<setprecision(4)<<m<< endl;			//��setprecision()��fixed���õ�ʱ�򣬲��̶ܹ�С�����ұߵ�λ��
}

void printOut(string str) {
	cout << setw(10) << right << str << endl;
}