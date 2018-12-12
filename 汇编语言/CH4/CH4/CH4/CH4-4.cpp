#include<stdio.h>
#include<string>

int getCount(char a[]) {
	//调用库函数获取字符串的长度
	int len = strlen(a);
	//count记录8出现的次数
	int count = 0;
	//遍历字符串，获取8出现的次数
	for (int i = 0; i < len; i++) {
		if (a[i] == '8')
			count++;
	}
	return count;
}

int main() {
	printf("Please enter a num: ");
	char a[100];
	//将用户输入的数字按照char的格式存入数组
	scanf("%s", a);		
	int count = getCount(a);
	printf("输入的数字中 8 出现的次数为： %d\n", count);
}