#include <iostream>
#include<cmath>
using namespace std;
int c[20], n = 8;
int count_ = 0;		//����һ�����������

//�ݹ��㷨����˻ʺ����⡣�ܹ���92�ֽⷨ��
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

void search(int num) {  //numΪ��ǰ��������num��ֵ��ʾ�ʺ���ڵڼ���
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
		if (flg) search(num + 1);		//������óɹ�,������ݹ�����һ�����ϵ�λ��
	}
}

int main() {
	search(0);
	cout << count_ << endl;
	return 0;
}