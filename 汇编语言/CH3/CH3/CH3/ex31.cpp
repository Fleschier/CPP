#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char s[100];			//������string�������ĵ�һ��ֵʼ��ΪF8���³������
	cout << "please enter a string: ";
	cin >> s;
	int len = strlen(s);

	_asm{
		LEA		ESI,s		
		MOV		ECX,len
		SUB		ESI,1
LOOP1:
		ADD		ESI,1
		MOV		AL,[ESI] 
		CALL	TOUPPER
		MOV		[ESI],AL
		SUB		ECX,1
		CMP		ECX,0
		JG		LOOP1

	}
	cout<<"the result is: "<<s<<endl;
	return 0;
		_asm{
TOUPPER:
		CMP		AL,'A'
		JB		END
		CMP		AL,'Z'
		JA		END
		ADD		AL, 20H
END:
		RET
	}

}