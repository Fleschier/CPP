//#include<iostream>
//#include<stack>
//#include <stdlib.h>
//#include<stdio.h>
//#include<cmath>
//
//
//using namespace std;
//
////��һ����ʽ��ת��Ϊ�沨�����ʽ
//
//class Ultra_Int{
//	int prefix;		//ϵ��
//	int body;		
//	int index;		//ָ��
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
//void tonibolan(char *ch, char arrch[100],int* Extra) {
//	int num_index = 0;
//	stack<char> st2;
//	int i = 0;
//	while (*ch != '\0') {					//�����ַ�����β����ѭ��
//		if(*ch >= '0'&&*ch <= '9') {
//			int pfix = 0;				//��ȡprefixλ
//			while (*ch !='&') {		//������������ֹһλ
//				pfix = pfix * 10 + *ch - '0';	//��0��ASCII����Ϊ��ת��Ϊ��ȷ����ֵ
//				++ch;
//			}
//
//			++ch;		//��ȡbodyλ
//			int bdy = 0;
//			while (*ch !='^') {
//				bdy = bdy * 10 + *ch - '0';
//				++ch;
//			}
//
//			++ch;		//��ȡindexλ
//			int idx = 0;
//			while (*ch >= '0'&&*ch <= '9') {
//				idx = idx * 10 + *ch - '0';
//				++ch;
//			}
//			--ch;
//			Ultra_Int tui(bdy, idx, pfix);
//			int tmp = tui.cal_data();		//����ֵ�������
//			arrch[i++] = '@';			//��@��ʾ������һ������
//			Extra[num_index++]=tmp;			//��ʵ�ʵ���ֵ�洢����һ��int������
//
//		}
//		else if (*ch == '(') {				//������ֱ��ѹջ
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
////�����沨�����ʽ��ֵ
//int calcval(char *rst,int* Extra) {								//��ָ����ʽ��������
//	int num_index = 0;
//
//	stack<int> st;						//��ʱջ
//	while (*rst != '\0') {
//		if (*rst >= '0'&&*rst <= '9') {				//���������ַ�������
//			st.push(*rst-'0');
//		}
//		else if (*rst == '@') {				//���������ַ���@������һ����Ĵ�����
//			int tmp = Extra[num_index++];
//			st.push(tmp);
//		}
//		else {							//�����������
//			switch (*rst) {
//			case'+': {
//				int a = st.top();
//				st.pop();
//				int b = st.top();
//				st.pop();					//���������֮ǰ��������
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
//				if (a != '0') {				//��ĸ��Ϊ��
//					st.push(b / a);
//				}
//				else {
//					cout << "����Ϊ0����" << endl;
//					exit(0);
//				}
//				break;
//			}
//			}
//		}
//		rst++;			//��ȡ��һ���ַ�
//	}
//	return st.top();
//}
//
//
//int main() {
//	cout << "����ʾ����3&5^2��ʾ3����5��ƽ�������" << endl;
//	int Extra[100];
//	char rst[100] = { 0 };
//	char arr_ch[100] = { 0 };
//	cin.get(arr_ch, 100);								//cin.get(�ַ�������, �����ַ���Ŀ)
//	tonibolan(arr_ch, rst, Extra);
//
//	cout << "\n��ʽ�ļ�����Ϊ��" << endl;
//	cout << calcval(rst, Extra) << endl;
//	return 0;
//}