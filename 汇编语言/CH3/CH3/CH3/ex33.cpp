#include<stdio.h>
#include<string>


int main() {
	char c[100];
	char res[100];
	printf("please enter a stirng: ");
	scanf("%s", c);
	int i = strlen(c);
	int index = 0;
	//for (int i = 0; i < strlen(c); i++) {
	//	if (c[i] >= 'A' && c[i] <= 'Z' || c[i] >= 'a' && c[i] <= 'z')
	//		res[index++] = c[i];
	//}
	;
	_asm {
		mov		ebx, index				//�ֲ�����index
		mov		ecx, i		//�ֲ�����i
		lea			eax, c				//c�׵�ַ
		lea			edx, res			//res�׵�ַ

		inc			ecx
		dec			eax
	NEXTChar:
		dec			ecx
		jz				END
		inc			eax
		cmp			[eax], 'z'
		ja				NEXTChar
		cmp			[eax], 'a'
		jb				NEXT
		//mov		[edx + ebx], [eax]
		mov		esi, [eax]
		mov		[edx + ebx],	esi
		inc			ebx
	NEXT:
		cmp			[eax], 'Z'
		ja				NEXTChar
		cmp			[eax], 'A'
		jb				NEXTChar
		//mov		[edx + ebx], [eax]
		mov		esi, [eax]
		mov		[edx + ebx], esi
		inc			ebx
		jmp			NEXTChar
		
	END:
		mov		index, ebx
	}
	for (int i = 0; i < index; i++) printf("%c", res[i]);
	printf("\n");
	return 0;
}