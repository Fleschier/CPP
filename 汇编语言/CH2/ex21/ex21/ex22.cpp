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
		JGE			MAXI				//有符号数大小比较，判断SF和OF。将较大的值传入maxi
		XCHG		EAX,	EBX		//保证较大的数存储在EAX中
	MAXI:
		MOV		maxi, EAX
		;
		MOV		ECX,	ui1
		MOV		EDX,	ui2
		CMP		ECX,	EDX
		JAE			MAXUI			//无符号数的比较，判断CF
		XCHG		ECX,	EDX		//保证较大的数存储在ECX中
	MAXUI:
		MOV		maxui,	ECX
	}
	cout << "按照有符号数比较较大的数为：" << maxi << endl;
	cout << "按照无符号数比较较大的数为：" << maxui << endl;
	return 0;
}