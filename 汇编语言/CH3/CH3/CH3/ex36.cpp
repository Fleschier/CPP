#include<stdio.h>

int main() {
	printf("please enter a char: ");
	char c;				
	scanf("%c", &c);
	char s[8];		//һ��ASCII����8λ����������
	_asm {
		xor				eax, eax
		mov			al, c
		lea				ebx, s
		mov			ecx, 8			//����ѭ��������
	LABEL1:
		rol				al, 1				//ѭ������һλ������ߵ�һλ����CF��־λ(ע�ⲻ��ZF)
		jnc					IFZERO			//��������һλΪ0		(jncָ�jump if not carry ��CF= 0��)
		mov			[ebx], 31H
		inc				ebx
		loop			LABEL1
		jmp				END

	IFZERO:
		mov			[ebx], 30H			//'0'��ASCII��Ϊ30H(16����)����48(10����)
		inc				ebx
		loop			LABEL1
		jmp				END
	END:
	}
	printf("%c ��ASCII������Ʊ�ʾΪ�� ", c);
	for (int i = 0; i < 8; i++)
		printf("%c", s[i]);
	printf("\n");
}