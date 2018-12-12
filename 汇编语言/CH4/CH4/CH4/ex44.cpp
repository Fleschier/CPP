#include<iostream>

void showCharArr(char arr[]) {
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
}

int main() {
	printf("Please enter a char: ");
	char c[5] = { 0 };
	scanf("%c", c);
	printf("Please enter number n: ");
	int n = 0;		//C++ 中 n需要初始化否则会报错， C不用
	scanf("%d", &n);		//这里要加取地址符
	//char* s = new char[n + 1];		//分配一个长度为n+1的数组来存储结果
	//但是遇到一个问题，new 申请的数组在打印的时候会报错，不知道为什么
	char s[100] = { 0 };
	_asm {
		mov		ECX, n
		lea			ESI, c		//源字符
		lea			EDI, s		//目的字符串
		call			GENERATE
	}

	showCharArr(s);
	//new 申请的空间需要手动释放
	//delete[] s;
	return 0;

	_asm{
	GENERATE:
		//子程序，生成字符串
		push		ebp
		mov		ebp, esp

	NEXT:
		movsb
		dec			ESI
		loop		NEXT

		mov		esp, ebp
		pop			ebp
		ret
	}
}