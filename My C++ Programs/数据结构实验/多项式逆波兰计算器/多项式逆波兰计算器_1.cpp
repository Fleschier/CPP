//#include<iostream>
//#include<stack>
//#include <stdlib.h>
//#include<stdio.h>
//#include<cmath>
//
//
//using namespace std;
//
////把一个算式先转化为逆波兰表达式
//
//class Ultra_Int{
//	int prefix;		//系数
//	int body;		
//	int index;		//指数
//
//public:
//	Ultra_Int(int bdy=1,int idx=1,int pfix=1) {
//		prefix = pfix;
//		body = bdy;
//		index = idx;
//	}
//
//	int cal_data() {
//		if (index == 0) {
//			return prefix;
//		}
//		else {
//			int tmp;
//			tmp = pow(body, index);
//			return prefix*tmp;
//		}
//	}
//};
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
//void tonibolan(char *ch, char arrch[100],int* Extra) {
//	int num_index = 0;
//	stack<char> st2;
//	int i = 0;
//	while (*ch != '\0') {					//读到字符串结尾结束循环
//		if(*ch >= '0'&&*ch <= '9') {
//			int pfix = 0;				//读取prefix位
//			while (*ch !='&') {		//如果输入的数不止一位
//				pfix = pfix * 10 + *ch - '0';	//减0的ASCII码是为了转化为正确的数值
//				++ch;
//			}
//
//			++ch;		//读取body位
//			int bdy = 0;
//			while (*ch !='^') {
//				bdy = bdy * 10 + *ch - '0';
//				++ch;
//			}
//
//			++ch;		//读取index位
//			int idx = 0;
//			while (*ch >= '0'&&*ch <= '9') {
//				idx = idx * 10 + *ch - '0';
//				++ch;
//			}
//			--ch;
//			Ultra_Int tui(bdy, idx, pfix);
//			int tmp = tui.cal_data();		//将数值计算出来
//			arrch[i++] = '@';			//用@表示这里是一个数字
//			Extra[num_index++]=tmp;			//将实际的数值存储在另一个int数组中
//
//		}
//		else if (*ch == '(') {				//左括号直接压栈
//			st2.push(*ch);
//		}
//		else if (*ch == ')') {
//			while (st2.top() != '(') {
//				arrch[i++] = st2.top();
//				st2.pop();
//			}
//			if (st2.top() == '(') {
//				st2.pop();
//			}
//		}
//		else if (st2.empty() || Priority(*ch)>Priority(st2.top())) {
//			st2.push(*ch);
//		}
//		else {
//			while (Priority(*ch) <= Priority(st2.top())) {
//				arrch[i++] = st2.top();
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
//		arrch[i++] = st2.top();
//		st2.pop();
//	}
//}
//
////计算逆波兰表达式的值
//int calcval(char *rst,int* Extra) {								//以指针形式传入数组
//	int num_index = 0;
//
//	stack<int> st;						//临时栈
//	while (*rst != '\0') {
//		if (*rst >= '0'&&*rst <= '9') {				//如果读入的字符是数字
//			st.push(*rst-'0');
//		}
//		else if (*rst == '@') {				//如果读入的字符是@，即是一个项的代符号
//			int tmp = Extra[num_index++];
//			st.push(tmp);
//		}
//		else {							//读入了运算符
//			switch (*rst) {
//			case'+': {
//				int a = st.top();
//				st.pop();
//				int b = st.top();
//				st.pop();					//读出运算符之前的两个数
//
//				st.push(a+b);	
//				break;
//			}
//			case'-': {
//				int a = st.top();
//				st.pop();
//				int b = st.top();
//				st.pop();
//				st.push(b-a);
//				break;
//			}
//			case'*': {
//				int a = st.top();
//				st.pop();
//				int b = st.top();
//				st.pop();
//				st.push(b*a);
//				break;
//			}
//			case'/': {
//				int a = st.top();
//				st.pop();
//				int b = st.top();
//				st.pop();
//				if (a != '0') {				//分母不为零
//					st.push(b / a);
//				}
//				else {
//					cout << "除数为0错误" << endl;
//					exit(0);
//				}
//				break;
//			}
//			}
//		}
//		rst++;			//读取下一个字符
//	}
//	return st.top();
//}
//
//
//int main() {
//	cout << "输入示例：3&5^2表示3倍的5的平方这个项" << endl;
//	int Extra[100];
//	char rst[100] = { 0 };
//	char arr_ch[100] = { 0 };
//	cin.get(arr_ch, 100);								//cin.get(字符数组名, 接收字符数目)
//	tonibolan(arr_ch, rst, Extra);
//
//	cout << "\n算式的计算结果为：" << endl;
//	cout << calcval(rst, Extra) << endl;
//	return 0;
//}