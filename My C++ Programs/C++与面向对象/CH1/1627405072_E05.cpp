#include<iostream>
using namespace std;

int main()
{
	int wst = 23 + 27;
	cout << "请输入距离：\n";
	int s;
	cin >> s;
	double a, b;
	a = wst + s / 3.0;
	b = s / 1.2;
	if (a>b) cout << "步行快\n";
	if (a == b) cout << "一样快\n";
	if (a<b) cout << "骑车快\n";
	return 0;
}