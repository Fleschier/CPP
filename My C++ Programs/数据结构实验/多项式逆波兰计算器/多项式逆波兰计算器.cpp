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
//	int prefix;			//����ʽϵ��
//	string x;					//����ʽ��ĸ
//	int tel;					//����ʽ����
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
////�������ȼ��� 
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
////ת������
//void tonibolan(char *ch, Ultra_char arrch[100]) {
//	stack<char> st2;
//	int i = 0;
//	while (*ch != '\0') {					//�����ַ�����β����ѭ��
//
//		if(*ch>='0'&&*ch<='9'){					//ϵ����Ϊһ�����������
//			int i = *ch-'0';							//ת��Ϊ����ֵ
//			++ch;
//			if (*ch >= 'A'&&*ch <= 'Z' || *ch >= 'a'&&*ch <= 'z') {
//				string c( ch);			//char*תΪstringֱ�Ӵ�ָ��ֵ�Ϳ���
//				++ch;
//				if (*ch == '^') ++ch;
//				int t = *ch-'0';				//ת��Ϊ����ֵ
//				Ultra_char tmp(i, c, t);
//				arrch[i++] = tmp;
//			}
//			else {
//				--ch;
//				Ultra_char tmp(i);					//���������ĸ����ΪNULL,tel����Ϊ���ֵ�ֵ;
//				arrch[i++] = tmp;
//			}
//		}
//
//		else if (*ch >= 'A'&&*ch <= 'Z' || *ch >= 'a'&&*ch <= 'z') {			//ϵ��Ϊһ����
//			string c(ch);
//			++ch;
//			if (*ch == '^') ++ch;
//			int t = *ch - '0';				//ת��Ϊ����ֵ
//			Ultra_char tmp(i, c, t);
//			arrch[i++] = tmp;
//		}
//
//		//�����:x="NULL",tel=0;
//		else if (*ch == '(') {				//������ֱ��ѹջ
//			st2.push(*ch);
//		}
//		else if (*ch == ')') {				//������������ţ�����ջ����ǰ���ݣ�ֱ�����������ţ������е��������������
//			while (st2.top() != '(') {
//				arrch[i++] = Ultra_char(st2.top(), 0);
//				st2.pop();
//			}
//			if (st2.top() == '(') {				//������������ջ
//				st2.pop();
//			}
//		}
//		//��������ͨ������ж�
//		else if (st2.empty() || Priority(*ch)>Priority(st2.top())) {		//���ȼ�����ֱ����ջ
//			st2.push(*ch);
//		}
//		else {
//			while (Priority(*ch) <= Priority(st2.top())) {		//���ȼ��͵��������������
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
////��ջ�е����������������(nΪ�ȴ���������ĸ�����signΪִ�е��������ͣ�+:1,-:2,*:3,/:4)
//Ultra_char* multi_add(stack<Ultra_char>& suc,  int n, int sign) {
//	Ultra_char uc1[10];
//	Ultra_char uc2[10];
//	for (int i = 0; i < n; i++) {
//		uc1[i] = suc.top();
//		suc.pop();
//	}
//}
//
////�����沨�����ʽ��ֵ
//stack<Ultra_char> calcval(Ultra_char *rst) {								//��ָ����ʽ��������
//	stack<Ultra_char> uc;					//�洢�������Ƕ����
//	stack<Ultra_char> st;						//��ʱջ2
//	while (rst->get_x() != "\0") {
//		if (rst->get_x()!="NULL") {				//���������ַ�����ĸ��
//			st.push(*rst);
//		}
//		else if (rst->get_x() == "NULL"&&rst->get_tel() == 1) {		//���������Ǵ�������
//			st.push(*rst);
//		}
//		else {							//�����������
//			string c = rst->get_x();
//			if(c=="+") {
//				Ultra_char a = st.top();
//				st.pop();
//				Ultra_char b = st.top();
//				st.pop();					//���������֮ǰ��������
//				if (a.get_tel() == b.get_tel()) {		//�����ָͬ����
//					st.push(a + b);
//				}
//				else {						//����ǲ�ָͬ����
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
//				if (a.get_tel() != 0) {				//��ĸ��Ϊ��
//					st.push(b / a);
//				}
//				else {
//					cout << "����Ϊ0����" << endl;
//					exit(0);
//				}
//			}
//		}
//		rst++;			//��ȡ��һ���ַ�
//	}
//	return uc;
//}
//
//
//	int main() {
//	Ultra_char rst[100];
//	char arr_ch[100];
//	stack<Ultra_char> suc;
//	cin.get(arr_ch, 100);								//cin.get(�ַ�������, �����ַ���Ŀ)
//	tonibolan(arr_ch, rst);
//	cout<<"��������ָ��֮ǰ�Է���'^'�ָ�"<<endl;
//	cout << "��ĸ���ִ�Сд" << endl;
//	cout << "��ʽ���沨�����ʽΪ��" << endl;
//	int i = 0;
//
//	while (rst[i].get_x() != "\0") {			//�����Ч����
//		cout << ' ' << rst[i++];
//	}
//
//	cout << "\n��ʽ�ļ�����Ϊ��" << endl;
//	suc = calcval(rst);
//	while (!suc.empty()) {
//		cout << suc.top();
//	}
//	return 0;
//}