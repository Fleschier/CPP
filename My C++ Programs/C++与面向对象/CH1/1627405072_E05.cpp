#include<iostream>
using namespace std;

int main()
{
	int wst = 23 + 27;
	cout << "��������룺\n";
	int s;
	cin >> s;
	double a, b;
	a = wst + s / 3.0;
	b = s / 1.2;
	if (a>b) cout << "���п�\n";
	if (a == b) cout << "һ����\n";
	if (a<b) cout << "�ﳵ��\n";
	return 0;
}