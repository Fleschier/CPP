#include<stdio.h>
#include<string>

int getCount(char a[]) {
	//���ÿ⺯����ȡ�ַ����ĳ���
	int len = strlen(a);
	//count��¼8���ֵĴ���
	int count = 0;
	//�����ַ�������ȡ8���ֵĴ���
	for (int i = 0; i < len; i++) {
		if (a[i] == '8')
			count++;
	}
	return count;
}

int main() {
	printf("Please enter a num: ");
	char a[100];
	//���û���������ְ���char�ĸ�ʽ��������
	scanf("%s", a);		
	int count = getCount(a);
	printf("����������� 8 ���ֵĴ���Ϊ�� %d\n", count);
}