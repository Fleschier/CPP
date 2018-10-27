//#include<iostream>
//#include<stack>
//#include <stdlib.h>
//#include<stdio.h>
//#include<string>
//
//using namespace std;
//int count = 0;
//
//class Ultra_char {
//	int prefix;			//多项式系数
//	string x;					//多项式字母
//	int tel;					//多项式级数
//public:
//	int get_pfx() {
//		return prefix;
//	}
//	string get_x() {
//		return x;
//	}
//	int get_tel() {
//		return tel;
//	}
//	Ultra_char(int pfix = 1, string c = "NULL", int i = 0) {
//		prefix = pfix;
//		x = c;
//		tel = i;
//	}
//	Ultra_char operator+(Ultra_char& uc) {
//		Ultra_char tp(uc.prefix + prefix, x, tel);
//		return tp;
//	}
//	Ultra_char operator - (Ultra_char& uc) {
//		return Ultra_char(prefix - uc.prefix, x, tel);
//	}
//	Ultra_char operator*(Ultra_char& uc) {
//		return Ultra_char(uc.prefix*prefix, x, uc.tel + tel);
//	}
//	Ultra_char operator/(Ultra_char& uc) {
//		return Ultra_char(prefix / uc.prefix, x, tel - uc.tel);
//	}
//	Ultra_char operator/(int i) {
//		if (i != 0) {
//			return Ultra_char(prefix / i, x, tel);
//		}
//	}
//	friend ostream& operator<<(ostream& os, Ultra_char& uc);
//};
//
//ostream& operator<<(ostream& os, Ultra_char& uc) {
//	if (uc.get_pfx() != 0) {
//		return os << uc.prefix << uc.x << '^' << uc.tel;
//	}
//	else {
//		return os << uc.x << endl;
//	}
//}
//
////定义优先级别 
//int Priority(char ch) {
//	int i;
//	switch (ch) {
//	case'(':i = 1; break;
//	case'+':i = 2; break;
//	case'-':i = 2; break;
//	case'*':i = 4; break;
//	case'/':i = 4; break;
//	case')':i = 5; break;
//	default:i = -1; break;
//	}
//	return i;
//}
//
////转化函数
//void tonibolan(char *ch, Ultra_char arrch[100]) {
//	stack<char> st2;
//	int i = 0;
//	while (*ch != '\0') {					//读到字符串结尾结束循环
//
//		if(*ch>='0'&&*ch<='9'){					//系数不为一的项或纯数字项
//			int i = *ch-'0';							//转化为数字值
//			++ch;
//			if (*ch >= 'A'&&*ch <= 'Z' || *ch >= 'a'&&*ch <= 'z') {
//				string c( ch);			//char*转为string直接传指针值就可以
//				++ch;
//				if (*ch == '^') ++ch;
//				int t = *ch-'0';				//转化为数字值
//				Ultra_char tmp(i, c, t);
//				arrch[i++] = tmp;
//			}
//			else {
//				--ch;
//				Ultra_char tmp(i);					//纯数字项，字母部分为NULL,tel部分为数字的值;
//				arrch[i++] = tmp;
//			}
//		}
//
//		else if (*ch >= 'A'&&*ch <= 'Z' || *ch >= 'a'&&*ch <= 'z') {			//系数为一的项
//			string c(ch);
//			++ch;
//			if (*ch == '^') ++ch;
//			int t = *ch - '0';				//转化为数字值
//			Ultra_char tmp(i, c, t);
//			arrch[i++] = tmp;
//		}
//
//		//运算符:x="NULL",tel=0;
//		else if (*ch == '(') {				//左括号直接压栈
//			st2.push(*ch);
//		}
//		else if (*ch == ')') {				//如果到了右括号，则在栈中向前回溯，直到遇到左括号，将其中的所有运算符读入
//			while (st2.top() != '(') {
//				arrch[i++] = Ultra_char(st2.top(), 0);
//				st2.pop();
//			}
//			if (st2.top() == '(') {				//遇到左括号则弹栈
//				st2.pop();
//			}
//		}
//		//下面是普通运算符判断
//		else if (st2.empty() || Priority(*ch)>Priority(st2.top())) {		//优先级高则直接入栈
//			st2.push(*ch);
//		}
//		else {
//			while (Priority(*ch) <= Priority(st2.top())) {		//优先级低的运算符先入数组
//				arrch[i++] = Ultra_char(st2.top(), 0);
//				st2.pop();
//				if (st2.empty()) {
//					break;
//				}
//			}
//			st2.push(*ch);
//		}
//		ch++;
//	}
//
//	while (!st2.empty()) {
//		arrch[i++] = Ultra_char(st2.top(), 0);
//		st2.pop();
//	}
//}
//
////从栈中弹出多个数进行运算(n为等待运算的数的个数，sign为执行的运算类型，+:1,-:2,*:3,/:4)
//Ultra_char* multi_add(stack<Ultra_char>& suc,  int n, int sign) {
//	Ultra_char uc1[10];
//	Ultra_char uc2[10];
//	for (int i = 0; i < n; i++) {
//		uc1[i] = suc.top();
//		suc.pop();
//	}
//}
//
////计算逆波兰表达式的值
//stack<Ultra_char> calcval(Ultra_char *rst) {								//以指针形式传入数组
//	stack<Ultra_char> uc;					//存储运算结果是多项的
//	stack<Ultra_char> st;						//临时栈2
//	while (rst->get_x() != "\0") {
//		if (rst->get_x()!="NULL") {				//如果读入的字符是字母项
//			st.push(*rst);
//		}
//		else if (rst->get_x() == "NULL"&&rst->get_tel() == 1) {		//如果读入的是纯数字项
//			st.push(*rst);
//		}
//		else {							//读入了运算符
//			string c = rst->get_x();
//			if(c=="+") {
//				Ultra_char a = st.top();
//				st.pop();
//				Ultra_char b = st.top();
//				st.pop();					//读出运算符之前的两个项
//				if (a.get_tel() == b.get_tel()) {		//如果是同指数项
//					st.push(a + b);
//				}
//				else {						//如果是不同指数项
//					uc.push(b);
//					uc.push(Ultra_char(0, "+", 0));
//					uc.push(a);
//				}
//			}
//			if (c == "-") {
//				Ultra_char a = st.top();
//				st.pop();
//				Ultra_char b = st.top();
//				st.pop();
//				if (a.get_tel() == b.get_tel()) {
//					st.push(b - a);
//				}
//				else {
//					st.push(b);
//					st.push(Ultra_char(0, "-", 0));
//					st.push(a);
//				}
//			}
//			if (c == "*") {
//				Ultra_char a = st.top();
//				st.pop();
//				Ultra_char b = st.top();
//				st.pop();
//				st.push(b * a);
//			}
//			if (c == "/") {
//				Ultra_char a = st.top();
//				st.pop();
//				Ultra_char b = st.top();
//				st.pop();
//				if (a.get_tel() != 0) {				//分母不为零
//					st.push(b / a);
//				}
//				else {
//					cout << "除数为0错误" << endl;
//					exit(0);
//				}
//			}
//		}
//		rst++;			//读取下一个字符
//	}
//	return uc;
//}
//
//
//	int main() {
//	Ultra_char rst[100];
//	char arr_ch[100];
//	stack<Ultra_char> suc;
//	cin.get(arr_ch, 100);								//cin.get(字符数组名, 接收字符数目)
//	tonibolan(arr_ch, rst);
//	cout<<"输入的项的指数之前以符号'^'分割"<<endl;
//	cout << "字母区分大小写" << endl;
//	cout << "算式的逆波兰表达式为：" << endl;
//	int i = 0;
//
//	while (rst[i].get_x() != "\0") {			//输出有效数据
//		cout << ' ' << rst[i++];
//	}
//
//	cout << "\n算式的计算结果为：" << endl;
//	suc = calcval(rst);
//	while (!suc.empty()) {
//		cout << suc.top();
//	}
//	return 0;
//}