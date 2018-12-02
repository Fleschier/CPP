#include<stdio.h>
#include<string>

int main(){
	printf("Please enter a string: ");
	char c[100];
	scanf("%s",c);
	int len = strlen(c);		//length of input
	//printf("%d\n", len);
	int ASC_num = 0;
	int DIGIT_num = 0;
	;
	_asm {
		MOV		EAX, ASC_num
		MOV		EBX, DIGIT_num
		LEA			EDX, c
		MOV		ESI,len
		DEC			EDX
	READNEXT:
		INC			EDX
		MOV		CL, [EDX]

		CALL		ISDIGIT
		CALL		ISASC
		MOV		ASC_num, EAX
		MOV		DIGIT_num, EBX
		DEC			ESI
		JNZ			READNEXT
	}
	printf("the number of digit is : %d\n", DIGIT_num);
	printf("the number of charactors is : %d\n", ASC_num);
	return 0;
	_asm{
	ISDIGIT:
		CMP		CL, '0'
		JB			END
		CMP		CL, '9'
		JA			END
		INC			EBX
	END:
		RET

	ISASC:
		CMP		CL,'A'
		JB			EXIT
		CMP		CL,'Z'
		JA			LABEL1
		INC			EAX
		JMP			EXIT
	LABEL1:
		CMP		CL,'a'
		JB			EXIT
		CMP		CL,'z'
		JA			EXIT
		INC			EAX
	EXIT:
		RET

	}

}