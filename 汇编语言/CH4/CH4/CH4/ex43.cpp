#include<iostream>

//���˵������ţ�ֻҪ���ַ����е����ֺ���ĸ��ȡ��������

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
	//����ַ���
	char res[100] = { 0 };
	_asm {
		lea			ESI, s
		lea			EDI, res
		mov		ECX, len		//����ѭ������

	NEXT:
		
		//�ж��Ƿ�������
		cmp			[ESI], '0'
		jl				CONTINUE
		cmp			[ESI], '9'
		jle			ACCEPT

		//�ж��Ƿ��Ǵ�д��ĸ
		cmp			[ESI], 'A'
		jl				CONTINUE
		cmp			[ESI], 'Z'
		jle			ACCEPT

		//�ж��Ƿ���Сд��ĸ
		cmp			[ESI], 'a'
		jl				CONTINUE
		cmp			[ESI], 'z'
		jle			ACCEPT

		//ʣ���û����ת�������ȫ�����Ǳ�����
	
	CONTINUE:			//�Ǳ�㣬������һ��ѭ��
		inc			ESI
		loop		NEXT
		jmp			END

	ACCEPT:				//���Ǳ�㣬 �����ַ�������ѭ��
		movsb	
		loop		NEXT
		jmp			END
	
	END:

	}
	showCharArr(res);
	return 0;
}