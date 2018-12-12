#include<iostream>

//过滤掉标点符号，只要将字符串中的数字和字母提取出来即可

void showCharArr(char arr[]) {
	int len = strlen(arr);
	if (len == 0) {
		printf("This is an blank string!\n");
		return;
	}
	for (int i = 0; i < len; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
}

int main() {
	printf("Please enter a string: ");
	char s[100];
	scanf("%s", s);
	int len = strlen(s);
	//结果字符串
	char res[100] = { 0 };
	_asm {
		lea			ESI, s
		lea			EDI, res
		mov		ECX, len		//设置循环次数

	NEXT:
		
		//判断是否是数字
		cmp			[ESI], '0'
		jl				CONTINUE
		cmp			[ESI], '9'
		jle			ACCEPT

		//判断是否是大写字母
		cmp			[ESI], 'A'
		jl				CONTINUE
		cmp			[ESI], 'Z'
		jle			ACCEPT

		//判断是否是小写字母
		cmp			[ESI], 'a'
		jl				CONTINUE
		cmp			[ESI], 'z'
		jle			ACCEPT

		//剩余的没有跳转的情况，全部都是标点符号
	
	CONTINUE:			//是标点，继续下一次循环
		inc			ESI
		loop		NEXT
		jmp			END

	ACCEPT:				//不是标点， 拷贝字符，继续循环
		movsb	
		loop		NEXT
		jmp			END
	
	END:

	}
	showCharArr(res);
	return 0;
}