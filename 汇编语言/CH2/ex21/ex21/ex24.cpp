#include<iostream>
#include<string>

using namespace std;

int main() {
	cout << "please enter a string(shorter than 100):";
	char s[100];
	int i = 0;
	cin >> s;
	;
	_asm {
			MOV		ESI,	i
			LEA			EAX,	[s]
		FG:
			MOV		BL,	[EAX]
			INC			EAX						//读取下一个字符
			INC			ESI
			CMP		BL,	0					//\0的ASCII码值为0
			JG			FG
			JE				OVER
		OVER:
			DEC			ESI
			MOV		i,	ESI

	}
	cout <<"输入的字符串的长度是："<< i<< endl;
	//cout << int('\0') << endl;

	return 0;
}