//#include<iostream>
//using namespace std;
//
//int calc(int m, int n,int& k);
//
//int main()
//{
//	cout << "please enter two integers:\n";
//	int m,n,km;
//	cin >> m >> n;
//	cout << m << " �� " << n << "���������Ϊ��" << calc(m, n, km) << endl;
//	cout << "��С������Ϊ��" << km << endl;
//	return 0;
//}
//
////���庯���������������С������------------------------
//int calc(int m, int n,int& k) {
//	if (m < n) {
//		int t = m; m = n; n = t;
//	}
//	for (int i = m;; i++) {
//		if (i%m == 0 && i%n == 0) {
//			k = i;
//			break;
//		}
//	}
//
//
//	for (int a=0;;) {
//		a = m%n;
//		m = n;
//		n = a;
//		if (n == 0) break;
//	}
//	return m;
//}