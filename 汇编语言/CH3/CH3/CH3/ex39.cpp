#include<stdio.h>
#include<string>

int main() {
	printf("please enter a number: ");
	char s[100];
	scanf("%s", s);		//将输入的数读成字符串
	int i = 0;							//十进制整数,用来存转化为10进制的11进制数
	char s1[100] = { 0 };				//14进制字符串， 注意要初始化，否则在strlen()获取长度的时候会将所有未初始化的部分也算入进去导致显示的时候是乱码
	int len = strlen(s);

	_asm {
		mov		eax, i
		lea			ebx, s
		mov		ecx, len
		push		ebx
		call			TODecimal
		add			esp, 4				//平衡堆栈
		mov		i, eax
		;
		push		eax
			lea			eax, s1			//写入转换后的结果为倒序
										//add			eax,99		//这里的加操作好像并不能指向数组的末尾？？？
			push		eax
			call			CONVERSION
			add			esp, 8
			;
	}

	printf("转化为10进制为 : %d\n", i);
	printf("转化为14进制为 : ");
	for (int i = strlen(s1); i >= 0; i--) {
		printf("%c", s1[i]);
	}
	printf("\n");
	return 0;

	_asm {
	TODecimal:
		push		ebp
			mov		ebp, esp
			mov		ebx, [ebp + 8]		//参数：char数组首地址
		NEXTCHAR :
			imul			eax, 11						//11进制
			xor			edx, edx				//将edx清空，下面用到dl来存char值，之后的加运算就不用扩展指令了
			//bl存的是char类型的数值，需要转化为对应的整数值。
			mov		dl, BYTE PTR[ebx]			//注意char类型只有一个字节，不能用32位寄存器来存！！
			//如果是'A'
			cmp			dl, 'A'
			je				LABEL1
			jmp			LABEL2
		LABEL1:
			sub			dl, 7
		LABEL2:
			sub			dl, 48				//'0'的ASCII码为48
			add			eax, edx			//sum = sum * 10 + b
			inc			ebx
			loop		NEXTCHAR
			mov		esp, ebp
			pop			ebp
			ret
			;

	CONVERSION:
		push		ebp
			mov			ebp, esp
			mov			eax, [ebp + 12]			//参数为一个数值
			mov			ecx, [ebp + 8]			//ecx初始指向目的数组的末尾地址

		CONTINUE :
			xor				edx, edx					//为除法做准备
			mov			esi, 14						//除数作为32位
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
			inc				ecx					
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