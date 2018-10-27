#include<iostream>

using namespace std;

int main() {
	cout << "please enter four charactors: ";
	char indata[5];  //输入四个字符需要容量为5的char数组
	cin >> indata;
	unsigned short int ui1, ui2;
	unsigned int i3;
	;
	_asm {
		PUSHAD										//将当前寄存器值EAX,ECX,EDX,EBX,ESP,EBP,ESI,EDI暂时存入堆栈
		LEA			EAX,	indata[0]
		MOV		BX,	[EAX]
		MOV		ui1,	BX
		LEA			EAX,	indata[2]
		MOV		CX,	[EAX]
		MOV		ui2,	CX
		LEA			EAX,	indata[0]
		MOV		EDX,	[EAX]
		MOV		i3,	EDX
		POPAD											//恢复各个寄存器的值
	}
	cout << "两个字数据分别为：" << ui1 << "	" << ui2 << endl;
	cout << "一个双字数据为：" << i3 << endl;

	return 0;
}