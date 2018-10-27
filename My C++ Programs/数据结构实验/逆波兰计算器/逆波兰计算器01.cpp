#include<iostream>
#include<stack>
#include <stdlib.h>
#include<stdio.h>


using namespace std;

//��һ����ʽ��ת��Ϊ�沨�����ʽ

//�������ȼ��� 
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

//ת������
void tonibolan(char *ch, char arrch[100]){
	stack<char> st2;
	int i = 0;
	while (*ch != '\0'){					//�����ַ�����β����ѭ��
		if (*ch >= '0'&&*ch <= '9'){
			arrch[i++] = *ch;
		}
		else if (*ch == '(') {				//������ֱ��ѹջ
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

//�����沨�����ʽ��ֵ
int calcval(char *rst){								//��ָ����ʽ��������

	stack<char> st;						//��ʱջ
	while (*rst != '\0'){
		if (*rst >= '0'&&*rst <= '9'){				//���������ַ�������
			st.push(*rst);
		}
		else{							//�����������
			switch (*rst){
			case'+':{
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();					//���������֮ǰ��������

				//����char������ӣ����Զ�ת����int�������㣬�õ��������ת��Ϊchar���͡�������ʽת����
				st.push(((a - '0') + (b - '0') + '0'));	//ע�����͵����㣬�����Ǵ�intת��Ϊchar
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
				if (a != '0'){				//��ĸ��Ϊ��
					st.push((((b - '0') / (a - '0')) + '0'));
				}
				else{
					cout << "����Ϊ0����" << endl;
					exit(0);
				}
				break;
			}
			}
		}
		rst++;			//��ȡ��һ���ַ�
	}
	return st.top() - '0';
}


int main(){
	char rst[100] = { 0 };
	char arr_ch[100] = { 0 };
	cin.get(arr_ch, 100);								//cin.get(�ַ�������, �����ַ���Ŀ)
	tonibolan(arr_ch, rst);
	cout << "��ʽ���沨�����ʽΪ��" << endl;
	int i = 0;

	while (rst[i]!='\0') {			//�����Ч����
		cout << ' ' << rst[i++];
	}

	cout << "\n��ʽ�ļ�����Ϊ��" << endl;
	cout << calcval(rst) << endl;  
	return 0;
}