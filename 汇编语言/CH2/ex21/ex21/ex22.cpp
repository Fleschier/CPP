#include<iostream>

using namespace std;

int main() {
	cout << "Please enter two inteagers: ";
	int i1, i2;
	unsigned int ui1, ui2;
	cin >> i1 >> i2;
	ui1 = abs(i1);
	ui2 = abs(i2);
	int maxi = 0;
	unsigned int maxui = 0;
	;
	_asm {
		MOV		EAX,	i1
		MOV		EBX,	i2
		CMP		EAX,	EBX
		JGE			MAXI				//�з�������С�Ƚϣ��ж�SF��OF�����ϴ��ֵ����maxi
		XCHG		EAX,	EBX		//��֤�ϴ�����洢��EAX��
	MAXI:
		MOV		maxi, EAX
		;
		MOV		ECX,	ui1
		MOV		EDX,	ui2
		CMP		ECX,	EDX
		JAE			MAXUI			//�޷������ıȽϣ��ж�CF
		XCHG		ECX,	EDX		//��֤�ϴ�����洢��ECX��
	MAXUI:
		MOV		maxui,	ECX
	}
	cout << "�����з������ȽϽϴ����Ϊ��" << maxi << endl;
	cout << "�����޷������ȽϽϴ����Ϊ��" << maxui << endl;
	return 0;
}