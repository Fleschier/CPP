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
			INC			EAX						//��ȡ��һ���ַ�
			INC			ESI
			CMP		BL,	0					//\0��ASCII��ֵΪ0
			JG			FG
			JE				OVER
		OVER:
			DEC			ESI
			MOV		i,	ESI

	}
	cout <<"������ַ����ĳ����ǣ�"<< i<< endl;
	//cout << int('\0') << endl;

	return 0;
}