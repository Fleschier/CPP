//#include<iostream>
//using namespace std;
//
//int Swap(int i);
//
//int main()
//{
//	cout << "[please enter a number:\n";
//	int m;
//	cin >> m;
//	cout << Swap(m) << endl;
//	return 0;
//}
//
////定义函数将数字逆序--------------------------
//int Swap(int i) {
//	int tmp = 0, t;
//	for (int j = 0;; j++) {
//		t = i % 10;	i /= 10;
//		tmp = 10 * tmp + t;
//		if (i == 0) break;
//	}
//	return tmp;
//}