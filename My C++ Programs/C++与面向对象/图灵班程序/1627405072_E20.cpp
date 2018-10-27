#include<iostream>
using namespace std;

int calc(int m, int n, int* k);

int main()
{
	cout << "please enter two integers:\n";
	int m, n, km=0;
	cin >> m >> n;
	cout << m << " 和 " << n << "的最大公因数为：" << calc(m, n, &km) << endl;
	cout<< "最小公倍数为：" << km << endl;
	return 0;
}

//定义函数求最大公因数和最小公倍数------------------------
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