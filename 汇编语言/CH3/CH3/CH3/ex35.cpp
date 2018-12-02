#include<stdio.h>
#include<string>

int main() {
	printf("please enter a string: ");
	char s[100];
	scanf("%s", s);
	int len = strlen(s);
	int asc_num = 0;
	int digit_num = 0;
	_asm {
		mov		eax, asc_num
		mov		edx, digit_num
		lea			esi, s					//取得s的首地址
		mov		ecx, len				//以ecx作为循环计数器
		dec			esi
	NEXTCHAR:
		inc			esi
		push		esi					//压入堆栈参数，这里esi存的是s的首地址			(注意如果要传值的话要取地址的值！！！)
		call			ISASC				//call也是转移到一个label，与jmp不同的是，转移的时候会将返回地址压入堆栈，所以调用的最后要ret
		add			esp, 4			//恢复堆栈
		loop		NEXTCHAR		

		mov		asc_num, eax
		mov		digit_num, edx

	}
	printf("the number of digits is : %d \n", digit_num);
	printf("the number of charactors is : %d \n", asc_num);
	return 0;
	_asm {
	ISASC:
		push		ebp
		mov		ebp, esp
		mov		ebx, [ebp + 8]	//读取传入参数。		这里的ebx存的是s的首地址，不是值！！！！！
		cmp			[ebx], 'A'
		jb				ISDIGIT				//ASCII小于60则判断是否为数字
		cmp			[ebx], 'Z'
		ja				UPPER
		inc			eax					//eax记录字符个数
		jmp			END
	UPPER:
		cmp			[ebx], 'z'
		ja				END
		cmp			[ebx], 'a'
		jb				END
		inc			eax
		jmp			END
	
	ISDIGIT:
		cmp			[ebx], '0'
		jb				END
		cmp			[ebx], '9'
		ja				END
		inc			edx				//edx记录数字个数
		jmp			END

	END:
		mov		esp, ebp
		pop			ebp
		ret

	}
}