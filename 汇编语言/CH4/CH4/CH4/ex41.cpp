#include<iostream>

void showCharArr(char arr[]) {
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
}

int main() {
	printf("Please enter a string: ");
	char s1[100];
	scanf("%s", s1);
	//s1的实际长度
	int len1 = strlen(s1);
	printf("Please enter another one: ");
	char s2[100];
	scanf("%s", s2);
	//s2的实际长度
	int len2 = strlen(s2);
	//结果字符串
	char res[200] = { 0 };
	_asm {
		lea			ESI, s1			//源串
		lea			EDI, res		//目的串
		mov		EAX, len1		//传入s1的长度作为循环次数
		push		EAX
		call		COPYSTR 
		add			ESP,4			//因为上面push了EAX，EAX占四个字节，所以平衡堆栈，将堆栈指针加4

		lea			ESI, s2		//s1处理结束之后处理s2
		mov		EAX,len2
		push		EAX
		call		COPYSTR
		add			ESP,4		//平衡堆栈
	}
	showCharArr(res);
	return 0;
	//子程序都写在return之后
	//子程序，拷贝一个字符串到另一个字符串
	_asm {
	COPYSTR:
		//子程序，建立堆栈框架
		push		ebp
		mov		ebp, esp
		mov		ECX, [ebp + 8]		//获取压入堆栈的参数，s1的长度作为循环次数
		rep			movsb				//使用REP重复前缀指令，循环len次，每次移动一个字符到目的串
		mov		esp,ebp
		pop			ebp
		ret
	}
}