#include<stdio.h>

int main() {
	printf("Please enter two natural numbers(seperated with a space : ");
	int i, j;
	scanf("%d %d", &i, &j);
	int sum = 0;
	int minus = 0;
	int mul = 0;

	_asm {
		mov	 ebx, i
		mov	 ecx, j
		push	 ecx		//先push j，再push i
		push	 ebx
		call		 SUM
		mov	 sum, eax
		call		 MINUS
		mov	minus, eax
		call		MULTI
		mov	mul, eax
		add		esp, 8		//注意前面push了两个值，需要恢复堆栈指针(指针增加)
	}
	printf("%d + %d =  %d\n", i, j, sum);
	printf("%d - %d = %d\n", i, j, minus);
	printf("%d * %d= %d\n", i, j, mul);
	return 0;

	_asm {
	SUM:
		push		ebp
		mov		ebp, esp
		mov		eax, [ebp + 8]		//传入参数读取i
		mov		ebx, [ebp + 12]		//j
		add			eax, ebx
		mov		esp ,ebp
		pop			ebp
		ret							//返回值通过EAX传出

	MINUS:
		push		ebp
		mov		ebp, esp
		mov		eax, [ebp + 8]
		mov		ebx, [ebp + 12]
		sub			eax,	 ebx
		mov		esp, ebp
		pop			ebp
		ret

	MULTI:
		push	ebp
		mov	ebp, esp
		mov	eax, [ebp + 8]
		mov	ebx, [ebp + 12]
		imul		eax, ebx
		mov	esp, ebp
		pop		ebp
		ret
	}

}