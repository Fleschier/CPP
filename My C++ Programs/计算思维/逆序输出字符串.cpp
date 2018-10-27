#include<stdio.h>
#include<string.h>

char str[100];
void StrReverse(char*,int);

int main()
{
	printf("请输入一串字符(长度不要超过99)：\n");
	int flag,i=0;
	char tmp = getchar();
	while (tmp != '\n') {
		str[i] = tmp;
		tmp = getchar();
		i++;
		flag = i;
	}
	StrReverse(str, flag-1);
	printf("\n");
	return 0;
}

void StrReverse(char* p,int n) {
	if (n >= 0) {
		printf("%c", p[n]);
		n--;
		StrReverse(p, n);
	}
}