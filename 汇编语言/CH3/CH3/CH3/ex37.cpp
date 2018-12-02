#include<stdio.h>
#include<string>

int main() {
	printf("please enter a number: ");
	int i ;							//十进制整数
	scanf("%d", &i);
	char s1[100] = {0};				//16进制字符串， 注意要初始化，否则在strlen()获取长度的时候会将所有未初始化的部分也算入进去导致显示的时候是乱码

	_asm {
		mov		eax, i
		;
		push		eax
		lea			eax, s1
		push		eax
		call			TOHexadecimal
		add			esp, 8
		;
	}

	printf("the number input is : %d\n", i);
	printf("the converted hexadecimal is : ");
	for (int i = strlen(s1); i >=0 ; i--) {
		printf("%c",s1[i]);
	}
	printf("H\n");
	return 0;

	_asm {

	TOHexadecimal:
		push		ebp
			mov			ebp, esp
			mov			eax, [ebp + 12]			//参数为一个数值
			mov			ecx, [ebp + 8]			//ecx初始指向目的数组的末尾地址

			CONTINUE :
			xor				edx, edx					//为除法做准备
			mov			esi, 16						//除数作为32位
			idiv				esi									//被除数在EDX:EAX中， 商在EAX，余数在EDX

			cmp				eax, 0					//如果商为0，则判断余数
			jle				LAST
			jmp				WRITERES
			LAST :
		//商为0，余数不为0时,写入余数，结束循环
		cmp				edx, 0
			jle				END
			//将余数写入
			WRITERES :
		mov			ebx, edx						//将商作为16进制的位, 由于是作为char，所以只需要低8位就够了
			add				bl, 48						//将数值转化为对应的ASCII码的值
			cmp				bl, 57						//如果超过9，则用字母来表示
			jg					PROCESS
			BACK :
		mov			BYTE PTR[ecx], bl
			inc				ecx						//指向数组的后一个位置
			jmp				CONTINUE

			PROCESS :		//转化为字母
		add				bl, 7							//例：如果是58，则加到65(10 -> A)
			jmp				BACK

			END :
		mov			esp, ebp
			pop				ebp
			ret
	}
}