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
	//s1��ʵ�ʳ���
	int len1 = strlen(s1);
	printf("Please enter another one: ");
	char s2[100];
	scanf("%s", s2);
	//s2��ʵ�ʳ���
	int len2 = strlen(s2);
	//����ַ���
	char res[200] = { 0 };
	_asm {
		lea			ESI, s1			//Դ��
		lea			EDI, res		//Ŀ�Ĵ�
		mov		EAX, len1		//����s1�ĳ�����Ϊѭ������
		push		EAX
		call		COPYSTR 
		add			ESP,4			//��Ϊ����push��EAX��EAXռ�ĸ��ֽڣ�����ƽ���ջ������ջָ���4

		lea			ESI, s2		//s1�������֮����s2
		mov		EAX,len2
		push		EAX
		call		COPYSTR
		add			ESP,4		//ƽ���ջ
	}
	showCharArr(res);
	return 0;
	//�ӳ���д��return֮��
	//�ӳ��򣬿���һ���ַ�������һ���ַ���
	_asm {
	COPYSTR:
		//�ӳ��򣬽�����ջ���
		push		ebp
		mov		ebp, esp
		mov		ECX, [ebp + 8]		//��ȡѹ���ջ�Ĳ�����s1�ĳ�����Ϊѭ������
		rep			movsb				//ʹ��REP�ظ�ǰ׺ָ�ѭ��len�Σ�ÿ���ƶ�һ���ַ���Ŀ�Ĵ�
		mov		esp,ebp
		pop			ebp
		ret
	}
}