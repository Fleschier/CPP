//#include<iostream>
//#include<cmath>
//using namespace std;
//
//bool isPrime(int n);
//
//int main()
//{
//	int count = 0;		//设置计数器
//	for (int i = 2; i <= 1000; i++){
//		if (isPrime(i)){
//			cout << i << "  ";
//			count++;
//			if (count % 8 == 0) {
//				cout << endl;
//			}
//		}
//	}
//	cout << endl;
//	return 0;
//}
////判断素数函数
//bool isPrime(int n) {
//	bool flag = true;			//设置标识变量
//	if (n == 2) return flag;
//	for (int i = 2; i <= (int)sqrt(n) + 1; i++) {
//		if (n%i == 0) {
//			flag = false; break;
//		}
//	}
//	return flag;
//}