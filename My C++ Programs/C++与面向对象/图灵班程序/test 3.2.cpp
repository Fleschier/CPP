////��һ����kת��Ϊ��n���Ʊ�ʾ����ʽ
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
//			if (tmp >= 10)  num[i] = tmp + 55;			//char(65)��Ӧ��ĸA
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
//				else cout << num[k];			//ע��˴���else����ʡ�������������ͱ�Ȼ��ִ�У���ԭ����ִ����������е�һ��
//			}
//			break;								//ע��˴���breakӦ����if����У����Ҳ��ܷ�����ѭ����
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
//	for (int i = 1;i < n + 1;i++) {							//Ҫ�����ͼ����ȷ����˴�i�����ֵҪ����������հ�setw�Ĳ���С1
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
//	for (int i = n;i >= 1;i--) {							//����ӡ������ʱ��ѭ������i�����ֵ��ȻҪ��������ƿո��setw�Ĳ���ֵС1
//		cout << setw(n - i + 1) << setfill(' ') << ' ';
//		for (int j = 1;j <= 2 * i - 1;j++) {
//			if (j % 2 == 1) cout << 'S';
//			else if (j % 2 == 0) cout << 'T';
//		}
//		cout << endl;
//	}
//	return 0;
//}

////NO.9 ĸţ����
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

////MO.10 ����·��
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
//	cout << "��ʮ�����·��Ϊ��" << sum << endl;
//	cout << "��ʮ����غ󷴵��߶�Ϊ��" << height << endl;
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
//					cout << "10Ԫ����" << i << "��";
//					cout << "5Ԫ��" << j << "��";
//					cout << "1Ԫ��" << k << "��";
//					cout << endl;
//				}
//			}
//	cout << "��" << count << "�ַ���" << endl;
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
//			cout << "   ";								//ע����������ӡ�Ŀո�������1����Ҫ��˫���ţ���Ȼ���������
//		}
//		cout << endl;
//	}
//	return 0;
//}

////NO.13 (1)  �žų˷���
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

//�žų˷���2��
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