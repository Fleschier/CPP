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
		lea			esi, s					//ȡ��s���׵�ַ
		mov		ecx, len				//��ecx��Ϊѭ��������
		dec			esi
	NEXTCHAR:
		inc			esi
		push		esi					//ѹ���ջ����������esi�����s���׵�ַ			(ע�����Ҫ��ֵ�Ļ�Ҫȡ��ַ��ֵ������)
		call			ISASC				//callҲ��ת�Ƶ�һ��label����jmp��ͬ���ǣ�ת�Ƶ�ʱ��Ὣ���ص�ַѹ���ջ�����Ե��õ����Ҫret
		add			esp, 4			//�ָ���ջ
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
		mov		ebx, [ebp + 8]	//��ȡ���������		�����ebx�����s���׵�ַ������ֵ����������
		cmp			[ebx], 'A'
		jb				ISDIGIT				//ASCIIС��60���ж��Ƿ�Ϊ����
		cmp			[ebx], 'Z'
		ja				UPPER
		inc			eax					//eax��¼�ַ�����
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
		inc			edx				//edx��¼���ָ���
		jmp			END

	END:
		mov		esp, ebp
		pop			ebp
		ret

	}
}