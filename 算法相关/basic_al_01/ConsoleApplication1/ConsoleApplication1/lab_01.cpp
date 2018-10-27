#include<iostream>
#include<string>
/*
 * P 008 1-1
 */

using namespace std;

int main() {
	cout << "please enter a num n: ";
	int n;
	cin >> n;

	//算法优化---- f(n) = n*10^(n-1)

	string tmp = to_string(n);		//需要string库
	int len = tmp.length();	//得到数字的位数
	int preRes;
	preRes = (len - 1) * pow(10, len - 2);		//几位数就是比他低一位的n个0到n个9的集合。
	int res[10];
	for (int i = 0; i < 10; i++) {
		res[i] = preRes;
	}
	//----------------

	int begin = pow(10, len-1);
	for (int i = begin; i <= n; i++) {
		if (i == 0) res[0] ++;
		int tmp = i;
		while (tmp != 0) {
			res[tmp % 10] ++;
			tmp = tmp / 10;
		}
	}

	int redundent = 0;
	for (int n = 0; n < len - 2; n++) {
		redundent = redundent * 10 + 10;
	}
	res[0] -= redundent;	//减去多余的0的个数
	//int res[10] = { 0 };
	//for (int i = 0; i <= n; i++) {
	//	int tmp = i;
	//	if (tmp == 0) {
	//		res[0] ++;
	//	}
	//	while (tmp != 0) {
	//		res[tmp % 10] ++;
	//		tmp = tmp / 10;
	//	}
	//}

	for (int i = 0; i < 10; i++) {
		cout << res[i] << endl;
	}
	return 0;
}