#include<iostream>
#include<stack>
#include <stdlib.h>
#include<stdio.h>


using namespace std;

//把一个算式先转化为逆波兰表达式

//定义优先级别 
int Priority(char ch){
	int i;
	switch (ch){
	case'(':i = 1; break;
	case'+':i = 2; break;
	case'-':i = 2; break;
	case'*':i = 4; break;
	case'/':i = 4; break;
	case')':i = 5; break;
	default:i = -1; break;
	}
	return i;
}

//转化函数
void tonibolan(char *ch, char arrch[100]){
	stack<char> st2;
	int i = 0;
	while (*ch != '\0'){					//读到字符串结尾结束循环
		if (*ch >= '0'&&*ch <= '9'){
			arrch[i++] = *ch;
		}
		else if (*ch == '(') {				//左括号直接压栈
			st2.push(*ch);
		}
		else if (*ch == ')'){
			while (st2.top() != '('){
				arrch[i++] = st2.top();
				st2.pop();
			}
			if (st2.top() == '('){
				st2.pop();
			}
		}
		else if (st2.empty() || Priority(*ch)>Priority(st2.top())){
			st2.push(*ch);
		}
		else{
			while (Priority(*ch) <= Priority(st2.top())){
				arrch[i++] = st2.top();
				st2.pop();
				if (st2.empty()){
					break;
				}
			}
			st2.push(*ch);
		}
		ch++;
	}

	while (!st2.empty()){
		arrch[i++] = st2.top();
		st2.pop();
	}
}

//计算逆波兰表达式的值
int calcval(char *rst){								//以指针形式传入数组

	stack<char> st;						//临时栈
	while (*rst != '\0'){
		if (*rst >= '0'&&*rst <= '9'){				//如果读入的字符是数字
			st.push(*rst);
		}
		else{							//读入了运算符
			switch (*rst){
			case'+':{
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();					//读出运算符之前的两个数

				//两个char类型相加，会自动转换成int类型运算，得到结果后再转换为char类型。这是隐式转换。
				st.push(((a - '0') + (b - '0') + '0'));	//注意类型的运算，这里是从int转换为char
				break;
			}
			case'-':{
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();
				st.push(((b - '0') - (a - '0')) + '0');
				break;
			}
			case'*':{
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();
				st.push(((b - '0')*(a - '0')) + '0');
				break;
			}
			case'/':{
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();
				if (a != '0'){				//分母不为零
					st.push((((b - '0') / (a - '0')) + '0'));
				}
				else{
					cout << "除数为0错误" << endl;
					exit(0);
				}
				break;
			}
			}
		}
		rst++;			//读取下一个字符
	}
	return st.top() - '0';
}


int main(){
	char rst[100] = { 0 };
	char arr_ch[100] = { 0 };
	cin.get(arr_ch, 100);								//cin.get(字符数组名, 接收字符数目)
	tonibolan(arr_ch, rst);
	cout << "算式的逆波兰表达式为：" << endl;
	int i = 0;

	while (rst[i]!='\0') {			//输出有效数据
		cout << ' ' << rst[i++];
	}

	cout << "\n算式的计算结果为：" << endl;
	cout << calcval(rst) << endl;  
	return 0;
}