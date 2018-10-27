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
//void swap(int & a,int & b)					//使用引用来达到形参与实参双向传递的效果
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

////多分支选择结构 switch(常量表达式) case(常量表达式) 语句,  常量表达式只能是整型，字符或枚举型
//#include<iostream>
//
//int main()
//{
//	using namespace std;
//	int grade;
//	cout << "please enter grade:\n";
//	cin >>grade;
//	switch (grade) {
//		case 90:cout << "A\n";break;		//若不加break，则满足条件的case语句之后的case语句都会得到执行。最后一个case语句可省略break。
//		case 80:cout << "B\n";break;
//		case 70:cout << "C\n";break;
//		default:cout << "None\n";
//	}
//	return 0;
//}

////if和else if的运用
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

////for 循环示例  注意for 和 while循环条件最后一个末尾都没有分号
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

////while 循环示例
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

////do-while 循环示例
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int sum = 0, i = 1;
//	do {
//		sum += i++;			//此处若把i++和i=1改为++i和i=0则结果不是5050而是5151
//	} while (i <= 100);
//	cout << sum << endl;
//	return 0;
//}

////用循环输出等边三角形（倒三角）
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int i = 1;i <= 10;++i) {
//		for (int j = 1;j <= i - 1;++j) {
//			cout << " ";
//		}
//		for (int k = 1;k <= 21 - 2 * i;++k) {		//注意计算好空格和字符间的数量关系
//			cout << "*";
//		}
//		cout << endl;
//	}
//	return 0;
//}

////输出按字母顺序组成的等边三角形(正向三角形)
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	for (int n = 1;n <= 10;n++) {
//		for (int i = 1;i <= 10 - n;i++) {			//注意空格的增长趋势与字符是相反的
//			cout << " ";
//		}
//		for (int j = 1;j <= 2 * n - 1;j++) {
//			cout << char('A' + j - 1);				//可以采用将字符用ASC码来表示的方法来输出
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

////素数判断
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
//	double sqrtm = sqrt(m*1.0);		//强制的将m转换为double类的数，所以要乘上1.0才行，或者采用 (double)m 的形式
//	for (int i = 2;i < sqrtm;i++) {
//		if (m%i == 0) {
//			cout << m << " isn't a prime" << endl;
//			return 1;				//这里的return 1表示退出函数（exit 表示退出进程）
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
//	cout << fixed << sqrt(x) << endl << sqrt(y) << endl;	//测试结果：x和y的平方根数值相同(fixed表示按一般规则显示小数，即保留6位)
//	return 0;
//}

////流式输出
//
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	cout.width(10);
//	cout.fill('m');			//设置输出的第一项宽度为10，空白字符全部用m来填充。这样可以达到多个输出同样字符的目的。（即上面的输出三角形）
//	cout << "k" << "   abcd" << endl;			//注意这里的宽度和填充字符设置只和第一个输出项有关
//
//
//	//包含在头文件iomanip 中的方法可以在输出流中使用
//	cout << setw(10) << setfill('m') << 'k' << "   abcd" << endl;	//同上，只作用于第一个输出项
//	return 0;
//}

////三角形输出两种方法对比
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()		//原版
//{
//	cout << "请输入一个整数：\n";
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
//int main()		//修订版*********************************************************************
//{
//	cout << "Please enter a number:\n";
//	int n;
//	cin >> n;
//	for (int i = 1;i < n;i++) {
//		cout << setw(n - i) << setfill(' ') << ' ';
//		cout << setw(2 * i - 1) << setfill('A') << 'A' << endl;		//注意补充的字符不会替换原来的字符，即使原本就是空字符也不会进行填充。
//	}
//	return 0;
//}


////用筛法求素数(用文件输入)
//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//
//int main()
//{
//	vector<int> prime(10000, 1);//将10000个向量元素都赋值为1，凡下表为1的就是素数（筛选过程中将不是素数的下标置0）
//	for (int i = 2;i < 100;++i) {		//10000个数，过滤到100就能排除所有的非素数了
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
//		if (1.0*pow(num, i - 1) / calculate(i - 1) <= 1e-8)  break;		//注意如果除法需要得到一个浮点数需要在前面乘以1.0
//		tot += 1.0*pow(-1, i)*pow(num,i-1) / calculate(i - 1);
//	}
//	cout.precision(9);													//注意precision的精度包含小数点
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

////NO.2  阶乘之和
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

////NO.3  求水仙花数
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

////NO.4  求1000之内的完数
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

////NO.5三位数是素数且是对称的
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

////NO.6  猴子吃桃子的问题
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "一共摘下了";
//	int sum = 1;
//	for (int i = 1;i <= 10;i++) {
//		sum+=(i + 1) * 2;
//	}
//	cout << sum << "个桃子" << endl;
//	return 0;
//}

//NO.7  打印图案
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "please enter a number:\n";
	int num;
	cin >> num;
	for (int i = 1;i < num+1;i++) {										//注意这里的循环条件必须是小于号，这样输出才会对齐
		cout << setw(num - i + 1) << setfill(' ') << ' ';
		cout << setw(2 * i - 1) << setfill('%') << '%' << endl;			//注意这里对i乘2减1要放在setw的括号里不能影响到前面空格的输出
	}
	return 0;
}