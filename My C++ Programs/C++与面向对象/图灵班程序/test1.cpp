//#include<iostream>
//
//void swap(int & a,int & b);
//int main()
//{
//	int num1, num2;
//	using namespace std;
//	cout << "this is my first c++ program!" << endl;
//	cout << "now i'll swap the numbers:" << endl;
//	num1 = 100;
//	num2 = 20;
//	cout << "first num1 is:" << num1 << endl << "num2 is:" << num2 << endl;
//	swap(num1, num2);
//	return 0;
//}
//
//void swap(int & a,int & b)					//ʹ���������ﵽ�β���ʵ��˫�򴫵ݵ�Ч��
//{
//	using std::cout;
//	using std::endl;
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//	cout << "after swap,now num1 is:" << a << endl;
//	cout << "num2 is:" << b << endl;
//}

//#include<iostream>
//
//using namespace std;
//int main()
//{
//	cout << "   *" << endl;
//	cout << "  ***" << endl;
//	cout << " *****" << endl;
//	cout << "*******" << endl;
//	cout << " *****" << endl;
//	cout << "  ***" << endl;
//	cout << "   *" << endl;
//
//}

////���֧ѡ��ṹ switch(�������ʽ) case(�������ʽ) ���,  �������ʽֻ�������ͣ��ַ���ö����
//#include<iostream>
//
//int main()
//{
//	using namespace std;
//	int grade;
//	cout << "please enter grade:\n";
//	cin >>grade;
//	switch (grade) {
//		case 90:cout << "A\n";break;		//������break��������������case���֮���case��䶼��õ�ִ�С����һ��case����ʡ��break��
//		case 80:cout << "B\n";break;
//		case 70:cout << "C\n";break;
//		default:cout << "None\n";
//	}
//	return 0;
//}

////if��else if������
//#include<iostream>
//
//int main()
//{
//	using namespace std;
//	int i;
//	cout << "please enter i:\n";
//	cin >> i;
//	if (i <= 0) {
//		cout << "i is negative.\n";
//	}
//	else if (i > 100) {
//		cout << "i is rather big\n";
//	}
//	else if (i > 0 && i <= 100) {
//		cout << "i is fitable" << endl;
//	}
//	return 0;
//}

////for ѭ��ʾ��  ע��for �� whileѭ���������һ��ĩβ��û�зֺ�
//#include<iostream>
//
//int main()
//{
//	using namespace std;
// 	int sum = 0;
//	for (int i = 1;i <= 100;i++) {
//		sum += i;
//	}
//	cout << sum << endl;
//	return 0;
//}

////while ѭ��ʾ��
//
//#include<iostream>
//
//using namespace std;
//int main()
//{
//	int sum = 0;
//	int i = 1;
//	while (i <= 100) {
//		sum += i;
//		i++;
//	}
//	cout << sum << endl;
//	return 0;
//}

////do-while ѭ��ʾ��
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int sum = 0, i = 1;
//	do {
//		sum += i++;			//�˴�����i++��i=1��Ϊ++i��i=0��������5050����5151
//	} while (i <= 100);
//	cout << sum << endl;
//	return 0;
//}

////��ѭ������ȱ������Σ������ǣ�
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 1;i <= 10;++i) {
//		for (int j = 1;j <= i - 1;++j) {
//			cout << " ";
//		}
//		for (int k = 1;k <= 21 - 2 * i;++k) {		//ע�����ÿո���ַ����������ϵ
//			cout << "*";
//		}
//		cout << endl;
//	}
//	return 0;
//}

////�������ĸ˳����ɵĵȱ�������(����������)
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int n = 1;n <= 10;n++) {
//		for (int i = 1;i <= 10 - n;i++) {			//ע��ո�������������ַ����෴��
//			cout << " ";
//		}
//		for (int j = 1;j <= 2 * n - 1;j++) {
//			cout << char('A' + j - 1);				//���Բ��ý��ַ���ASC������ʾ�ķ��������
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

////�����ж�
//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	cout << "please enter a  number :" << endl;
//	int m;
//	cin >> m;
//	double sqrtm = sqrt(m*1.0);		//ǿ�ƵĽ�mת��Ϊdouble�����������Ҫ����1.0���У����߲��� (double)m ����ʽ
//	for (int i = 2;i < sqrtm;i++) {
//		if (m%i == 0) {
//			cout << m << " isn't a prime" << endl;
//			return 1;				//�����return 1��ʾ�˳�������exit ��ʾ�˳����̣�
//		}
//	}
//	cout << m << " is a prime." << endl;
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	double x = 1000;
//	int y = 1000;
//
//	cout << fixed << sqrt(x) << endl << sqrt(y) << endl;	//���Խ����x��y��ƽ������ֵ��ͬ(fixed��ʾ��һ�������ʾС����������6λ)
//	return 0;
//}

////��ʽ���
//
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	cout.width(10);
//	cout.fill('m');			//��������ĵ�һ����Ϊ10���հ��ַ�ȫ����m����䡣�������Դﵽ������ͬ���ַ���Ŀ�ġ������������������Σ�
//	cout << "k" << "   abcd" << endl;			//ע������Ŀ�Ⱥ�����ַ�����ֻ�͵�һ��������й�
//
//
//	//������ͷ�ļ�iomanip �еķ����������������ʹ��
//	cout << setw(10) << setfill('m') << 'k' << "   abcd" << endl;	//ͬ�ϣ�ֻ�����ڵ�һ�������
//	return 0;
//}

////������������ַ����Ա�
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()		//ԭ��
//{
//	cout << "������һ��������\n";
//	int n;
//	cin >> n;
//	for (int i = 1;i <= n;i++) {
//		for (int j = 1;j <= n - i;j++) {
//			cout << " ";
//		}
//		for (int m = 1;m <= 2 * i - 1;m++) {
//			cout << char('A' + m - 1) ;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//
//int main()		//�޶���*********************************************************************
//{
//	cout << "Please enter a number:\n";
//	int n;
//	cin >> n;
//	for (int i = 1;i < n;i++) {
//		cout << setw(n - i) << setfill(' ') << ' ';
//		cout << setw(2 * i - 1) << setfill('A') << 'A' << endl;		//ע�ⲹ����ַ������滻ԭ�����ַ�����ʹԭ�����ǿ��ַ�Ҳ���������䡣
//	}
//	return 0;
//}


////��ɸ��������(���ļ�����)
//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//
//int main()
//{
//	vector<int> prime(10000, 1);//��10000������Ԫ�ض���ֵΪ1�����±�Ϊ1�ľ���������ɸѡ�����н������������±���0��
//	for (int i = 2;i < 100;++i) {		//10000���������˵�100�����ų����еķ�������
//		if (prime[i]) {
//			for (int j = i;i*j < 10000;++j) {
//				prime[i*j] = 0;
//			}
//		}
//		ifstream in("a.txt");
//		for (int a;in >> a && a > 1 && a < 10000;) {
//			cout << a << "is" << (prime[a] ? "" : "not ") << "a prime.\n";
//		}
//	}
//	return 0;
//}

////exercise 2 NO.1
//#include<iostream>
//#include<cmath>
//#include<iomanip>
//using namespace std;
//
//int calculate(int i);
//
//int main()
//{
//	int num;
//	cout << "please enter a number:\n";
//	cin >> num;
//	double tot = 1;
//	for (int i = 2;;i++) {
//		if (1.0*pow(num, i - 1) / calculate(i - 1) <= 1e-8)  break;		//ע�����������Ҫ�õ�һ����������Ҫ��ǰ�����1.0
//		tot += 1.0*pow(-1, i)*pow(num,i-1) / calculate(i - 1);
//	}
//	cout.precision(9);													//ע��precision�ľ��Ȱ���С����
//	cout << "the result is:" << tot << endl;
//	return 0;
//}
//
//int calculate(int i) {
//	int tmp = 1;
//	for (int j = i;j >= 1;j--) {
//		tmp *= j;
//	}
//	return tmp;
//}

////NO.2  �׳�֮��
//#include<iostream>
//using namespace std;
//
//long long multi(int i);
//int main()
//{
//	cout << "please enter a number:\n";
//	int num;
//	cin >> num;
//	long long sum = 0;
//	for (int n = 1;n <= num;n++) {
//		sum += multi(n);
//	}
//	cout << "the result is:" << sum << endl;
//	return 0;
//}
//
//long long  multi(int i) {
//	long long tmp = 1;
//	for (int j = 1;j <= i;j++) {
//		tmp *= j;
//	}
//	return tmp;
//}

////NO.3  ��ˮ�ɻ���
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	cout << "the results are:\n";
//	for (int i = 100;i <= 999;i++) {
//		a = i / 100;
//		b = i / 10 % 10;
//		c = i % 10;
//		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
//			cout << i << endl;
//	}
//	return 0;
//}

////NO.4  ��1000֮�ڵ�����
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 1;i <= 1000;i++) {
//		int tmp = 0;
//		for (int j = 1;j < i;j++) {
//			if (i%j == 0) {
//				tmp += j;
//			}
//		}
//		if (tmp == i)
//			cout << i << endl;
//	}
//	return 0;
//}

////NO.5��λ�����������ǶԳƵ�
//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int reverse(int i);
//int judge(int i);
//
//int main()
//{
//	cout << "the results are:\n";
//	for (int i = 100;i <= 999;i++) {
//		if (reverse(i) && judge(i))
//			cout << i << endl;
//	}
//	return 0;
//}
//
//int judge(int i) {
//	for (int j = 2;j < sqrt(i)+1;j++) {
//		if (i%j == 0)
//			return 0;
//			
//		return i;	
//	}
//}
//
//int reverse(int i) {
//	int a, b, c, tmp;
//	a = i / 100;
//	b = i / 10 % 10;
//	c = i % 10;
//	tmp = 100 * c + 10 * b + a;
//	if (tmp == i)
//		return i;
//	else
//		return 0;
//}

////NO.6  ���ӳ����ӵ�����
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "һ��ժ����";
//	int sum = 1;
//	for (int i = 1;i <= 10;i++) {
//		sum+=(i + 1) * 2;
//	}
//	cout << sum << "������" << endl;
//	return 0;
//}

//NO.7  ��ӡͼ��
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "please enter a number:\n";
	int num;
	cin >> num;
	for (int i = 1;i < num+1;i++) {										//ע�������ѭ������������С�ںţ���������Ż����
		cout << setw(num - i + 1) << setfill(' ') << ' ';
		cout << setw(2 * i - 1) << setfill('%') << '%' << endl;			//ע�������i��2��1Ҫ����setw�������ﲻ��Ӱ�쵽ǰ��ո�����
	}
	return 0;
}