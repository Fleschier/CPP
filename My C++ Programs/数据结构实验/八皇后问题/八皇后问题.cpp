#include <iostream>
#include<cmath>
using namespace std;
int c[20], n = 8;
int count_ = 0;		//计数一共多少种情况

//递归算法解决八皇后问题。总共有92种解法。
void show_arr() {
	//n=8
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (j == c[i]) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}

void search(int num) {  //num为当前的列数，num的值表示皇后放在第几行
	if (num == n) {
		show_arr();
		++count_;
	}
	for (int i = 0; i<n; i++) {	
		c[num] = i;
		int flg = 1;
		for (int j = 0; j<num; ++j)	
			if (c[num] == c[j] || abs(num - j) == abs(c[num] - c[j]) ) {
				flg = 0;
				break;
			}
		if (flg) search(num + 1);		//如果放置成功,则继续递归找下一个符合的位置
	}
}

int main() {
	search(0);
	cout << count_ << endl;
	return 0;
}