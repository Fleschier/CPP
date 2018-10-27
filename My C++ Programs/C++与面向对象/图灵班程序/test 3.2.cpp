////将一个数k转换为其n进制表示的形式
//#include<iostream>
//using namespace std;
//int num[100] = { 0 };
//
//void show();
//
//int main()
//{
//	cout << "enter k:\n";
//	int k,n;
//	cin >> k;
//	cout << "enter n:\n";
//	cin >> n;
//	if (n <= 1) cout << "wrong type" << endl;
//
//	else if (2 <= n&&n < 10) {
//		for (int i = 0;i <= 99;i++) {
//			num[i] = k % n;
//			k = k / n;
//			if (k == 0) break;
//		}
//		show();
//	}
//
//	else if (n >= 11 && n <= 16) {
//		for (int i = 0;i <= 99;i++) {
//			int tmp = k%n;
//			if (tmp >= 10)  num[i] = tmp + 55;			//char(65)对应字母A
//			else num[i] = tmp;
//			k = k / n;
//			if (k == 0) break;
//		}
//		show();
//	}
//	
//	return 0;
//}
//
//void show() {
//	for (int j = 99;j >= 0;j--) {
//		if (num[j]) {
//			for (int k = j;k >= 0;k--) {
//				if (num[k] >= 11) cout << char(num[k]);
//				else cout << num[k];			//注意此处的else不能省，否则这条语句就必然会执行，而原意是执行两条语句中的一句
//			}
//			break;								//注意此处的break应放在if语句中，并且不能放在内循环中
//		}
//	}
//	cout << endl;
//}

//book test
////NO.8(1)
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	cout << "please enter n:\n";
//	int n;
//	cin >> n;
//	for (int i = 1;i < n + 1;i++) {							//要输出的图像正确，则此处i的最大值要比下面输出空白setw的参数小1
//		cout << setw(n - i + 1) << setfill(' ') << ' ';
//		cout << setw(i) << setfill('#') << '#';
//		cout << setw(5) << setfill(' ') << ' ';
//		cout << setw(i) << setfill('$') << '$';
//		cout << endl;
//	}
//	return 0;
//}

////NO.8(2)
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	cout << "please enter n:\n";
//	int n;
//	cin >> n;
//	for (int i = n;i >= 1;i--) {							//当打印倒三角时，循环条件i的最大值依然要比下面控制空格的setw的参数值小1
//		cout << setw(n - i + 1) << setfill(' ') << ' ';
//		for (int j = 1;j <= 2 * i - 1;j++) {
//			if (j % 2 == 1) cout << 'S';
//			else if (j % 2 == 0) cout << 'T';
//		}
//		cout << endl;
//	}
//	return 0;
//}

////NO.9 母牛问题
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "please enter n:\n";
//	int n, tot = 1;
//	cin >> n;
//	for (int i = 1;i <= n;i++) {
//		if (i % 4 == 0) {
//			tot *= 2;
//		}
//	}
//	cout << "the final number of cows is :" << tot << endl;
//	return 0;
//}

////MO.10 弹球路程
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	float sum=0, height=100;
//	cout << "please enter n:\n";
//
//	for (int i = 1;i <= 10;i++) {
//		sum += height;
//		height /= 2;
//		sum += height;
//	}
//	cout << "第十次落地路程为：" << sum << endl;
//	cout << "第十次落地后反弹高度为：" << height << endl;
//	return 0;
//}

////NO.11
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int count = 0;
//	for (int i = 1;i <= 9;i++)
//		for (int j = 1;j <= 17;j++)
//			for (int k = 1;k <= 85;k++) {
//				if (10 * i + 5 * j + k == 100) {
//					count += 1;
//					cout << "10元共：" << i << "个";
//					cout << "5元共" << j << "个";
//					cout << "1元共" << k << "个";
//					cout << endl;
//				}
//			}
//	cout << "共" << count << "种方案" << endl;
//	return 0;
//}

////NO.12(1)
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int num[7] = { 0,1,2,3,4,5,6 };
//
//int main()
//{
//	for (int i = 1;i <= 6;i++) {
//		cout << left << setw(5) << i;
//		for (int j = i - 1;j <= i + 5;j++) {
//			int tmp = j;
//			while (tmp > 6)	 tmp -= 7;
//			cout << setw(4) << num[tmp];
//		}
//		cout << endl;
//	}
//	return 0;
//}

////NO.12(2)
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 1;i <= 6;i++) {
//		for (int j = 1;j <= 7;j++) {
//			cout << "(" << i << "," << j << ")";
//			cout << "   ";								//注意如果这里打印的空格数不是1，则要用双引号，不然会出现乱码
//		}
//		cout << endl;
//	}
//	return 0;
//}

////NO.13 (1)  九九乘法表
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	cout << "* ";
//	for (int i = 1;i <= 9;i++) cout << setw(5) << i;
//	cout << endl;
//	for (int i = 1;i <= 50;i++) cout << '-';
//	cout << endl;
//
//	for (int i = 1;i <= 9;i++) {
//		cout << setw(6) << left << i;
//		for (int j = 1;j <= i;j++) {
//			cout << setw(5) << i*j;
//		}
//		cout << endl;
//	}
//	return 0;
//}

//九九乘法表（2）
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "* ";
	for (int i = 1;i <= 9;i++) cout << setw(5) << i;
	cout << endl;
	for (int i = 1;i <= 50;i++) cout << '-';
	cout << endl;

	for (int i = 1;i <= 9;i++) {
		cout << left << setw(6) << i;
		for (int j = 1;j <= 9;j++) {
			if (j >= i)cout << setw(5) << i*j;
			else cout << setw(5) << ' ';
		}
		cout << endl;
	}

	return 0;
}