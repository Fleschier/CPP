#include<iostream>

using namespace std;

int main() {
	char cArr[10] = { 1,2,-3,4,5,6,-7,8,9,-10 };
	int negative = 0;
	int positive = 0;
	;
	_asm {
		SUB			EAX, EAX
		MOV		EDX, negative
		MOV		ESI, positive
		;
	CIR:
		LEA			EBX,	cArr[EAX]
		MOV		CL,	[EBX]			//注意是8位的数字
		CMP		CL,	0
		JGE			POSI
		JL				NEGA
		;
	POSI:
		INC			ESI
		JNS			INCRE
		;
	NEGA:
		INC			EDX
		JMP		INCRE
		;
	INCRE:
		INC			EAX
		CMP		EAX,	10
		JGE			OVER
		JL				CIR
		;
	OVER:
		MOV		negative,	EDX
		MOV		positive,		ESI
	}
	cout << "负数有" << negative << "个" << endl;
	cout << "正数有" << positive << "个" << endl;
	return 0;
}