#include<stdio.h>
#include<string>

int main() {
	printf("please enter a number: ");
	int i ;							//ʮ��������
	scanf("%d", &i);
	char s1[100] = {0};				//16�����ַ����� ע��Ҫ��ʼ����������strlen()��ȡ���ȵ�ʱ��Ὣ����δ��ʼ���Ĳ���Ҳ�����ȥ������ʾ��ʱ��������

	_asm {
		mov		eax, i
		;
		push		eax
		lea			eax, s1
		push		eax
		call			TOHexadecimal
		add			esp, 8
		;
	}

	printf("the number input is : %d\n", i);
	printf("the converted hexadecimal is : ");
	for (int i = strlen(s1); i >=0 ; i--) {
		printf("%c",s1[i]);
	}
	printf("H\n");
	return 0;

	_asm {

	TOHexadecimal:
		push		ebp
			mov			ebp, esp
			mov			eax, [ebp + 12]			//����Ϊһ����ֵ
			mov			ecx, [ebp + 8]			//ecx��ʼָ��Ŀ�������ĩβ��ַ

			CONTINUE :
			xor				edx, edx					//Ϊ������׼��
			mov			esi, 16						//������Ϊ32λ
			idiv				esi									//��������EDX:EAX�У� ����EAX��������EDX

			cmp				eax, 0					//�����Ϊ0�����ж�����
			jle				LAST
			jmp				WRITERES
			LAST :
		//��Ϊ0��������Ϊ0ʱ,д������������ѭ��
		cmp				edx, 0
			jle				END
			//������д��
			WRITERES :
		mov			ebx, edx						//������Ϊ16���Ƶ�λ, ��������Ϊchar������ֻ��Ҫ��8λ�͹���
			add				bl, 48						//����ֵת��Ϊ��Ӧ��ASCII���ֵ
			cmp				bl, 57						//�������9��������ĸ����ʾ
			jg					PROCESS
			BACK :
		mov			BYTE PTR[ecx], bl
			inc				ecx						//ָ������ĺ�һ��λ��
			jmp				CONTINUE

			PROCESS :		//ת��Ϊ��ĸ
		add				bl, 7							//���������58����ӵ�65(10 -> A)
			jmp				BACK

			END :
		mov			esp, ebp
			pop				ebp
			ret
	}
}