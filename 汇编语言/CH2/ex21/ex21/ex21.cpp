#include<iostream>

using namespace std;

int main() {
	cout << "please enter four charactors: ";
	char indata[5];  //�����ĸ��ַ���Ҫ����Ϊ5��char����
	cin >> indata;
	unsigned short int ui1, ui2;
	unsigned int i3;
	;
	_asm {
		PUSHAD										//����ǰ�Ĵ���ֵEAX,ECX,EDX,EBX,ESP,EBP,ESI,EDI��ʱ�����ջ
		LEA			EAX,	indata[0]
		MOV		BX,	[EAX]
		MOV		ui1,	BX
		LEA			EAX,	indata[2]
		MOV		CX,	[EAX]
		MOV		ui2,	CX
		LEA			EAX,	indata[0]
		MOV		EDX,	[EAX]
		MOV		i3,	EDX
		POPAD											//�ָ������Ĵ�����ֵ
	}
	cout << "���������ݷֱ�Ϊ��" << ui1 << "	" << ui2 << endl;
	cout << "һ��˫������Ϊ��" << i3 << endl;

	return 0;
}