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
	int n = 0;		//C++ �� n��Ҫ��ʼ������ᱨ�� C����
	scanf("%d", &n);		//����Ҫ��ȡ��ַ��
	//char* s = new char[n + 1];		//����һ������Ϊn+1���������洢���
	//��������һ�����⣬new ����������ڴ�ӡ��ʱ��ᱨ����֪��Ϊʲô
	char s[100] = { 0 };
	_asm {
		mov		ECX, n
		lea			ESI, c		//Դ�ַ�
		lea			EDI, s		//Ŀ���ַ���
		call			GENERATE
	}

	showCharArr(s);
	//new ����Ŀռ���Ҫ�ֶ��ͷ�
	//delete[] s;
	return 0;

	_asm{
	GENERATE:
		//�ӳ��������ַ���
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