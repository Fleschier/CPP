#include<stdio.h>

int main() {
	printf("please enter a char: ");
	char c;				
	scanf("%c", &c);
	char s[8];		//一个ASCII码用8位二进制来存
	_asm {
		xor				eax, eax
		mov			al, c
		lea				ebx, s
		mov			ecx, 8			//设置循环计数器
	LABEL1:
		rol				al, 1				//循环左移一位，最左边的一位移入CF标志位(注意不是ZF)
		jnc					IFZERO			//如果移入的一位为0		(jnc指令：jump if not carry （CF= 0）)
		mov			[ebx], 31H
		inc				ebx
		loop			LABEL1
		jmp				END

	IFZERO:
		mov			[ebx], 30H			//'0'的ASCII码为30H(16进制)或者48(10进制)
		inc				ebx
		loop			LABEL1
		jmp				END
	END:
	}
	printf("%c 的ASCII码二进制表示为： ", c);
	for (int i = 0; i < 8; i++)
		printf("%c", s[i]);
	printf("\n");
}