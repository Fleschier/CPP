#include<iostream>
using namespace std;

int calc(int m, int n, int* k);

int main()
{
	cout << "please enter two integers:\n";
	int m, n, km=0;
	cin >> m >> n;
	cout << m << " �� " << n << "���������Ϊ��" << calc(m, n, &km) << endl;
	cout<< "��С������Ϊ��" << km << endl;
	return 0;
}

//���庯���������������С������------------------------
int calc(int m, int n, int* k) {
	int a = m, b = n;
	if (m < n) {
		int t = m; m = n; n = t;
	}
  	for (int i = a;; i++) {
		if (i%a == 0 && i%b == 0) {
			*k = i;
			break;
		}
	}
	for (int a = 0;;) {
		a = m%n;
		m = n;
		n = a;
		if (n == 0) break;
	}
	return m;
}