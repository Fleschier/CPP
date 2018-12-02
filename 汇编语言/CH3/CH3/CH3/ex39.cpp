#include<stdio.h>
#include<string>

int main() {
	printf("please enter a number: ");
	char s[100];
	scanf("%s", s);		//��������������ַ���
	int i = 0;							//ʮ��������,������ת��Ϊ10���Ƶ�11������
	char s1[100] = { 0 };				//14�����ַ����� ע��Ҫ��ʼ����������strlen()��ȡ���ȵ�ʱ��Ὣ����δ��ʼ���Ĳ���Ҳ�����ȥ������ʾ��ʱ��������
	int len = strlen(s);

	_asm {
		mov		eax, i
		lea			ebx, s
		mov		ecx, len
		push		ebx
		call			TODecimal
		add			esp, 4				//ƽ���ջ
		mov		i, eax
		;
		push		eax
			lea			eax, s1			//д��ת����Ľ��Ϊ����
										//add			eax,99		//����ļӲ������񲢲���ָ�������ĩβ������
			push		eax
			call			CONVERSION
			add			esp, 8
			;
	}

	printf("ת��Ϊ10����Ϊ : %d\n", i);
	printf("ת��Ϊ14����Ϊ : ");
	for (int i = strlen(s1); i >= 0; i--) {
		printf("%c", s1[i]);
	}
	printf("\n");
	return 0;

	_asm {
	TODecimal:
		push		ebp
			mov		ebp, esp
			mov		ebx, [ebp + 8]		//������char�����׵�ַ
		NEXTCHAR :
			imul			eax, 11						//11����
			xor			edx, edx				//��edx��գ������õ�dl����charֵ��֮��ļ�����Ͳ�����չָ����
			//bl�����char���͵���ֵ����Ҫת��Ϊ��Ӧ������ֵ��
			mov		dl, BYTE PTR[ebx]			//ע��char����ֻ��һ���ֽڣ�������32λ�Ĵ������棡��
			//�����'A'
			cmp			dl, 'A'
			je				LABEL1
			jmp			LABEL2
		LABEL1:
			sub			dl, 7
		LABEL2:
			sub			dl, 48				//'0'��ASCII��Ϊ48
			add			eax, edx			//sum = sum * 10 + b
			inc			ebx
			loop		NEXTCHAR
			mov		esp, ebp
			pop			ebp
			ret
			;

	CONVERSION:
		push		ebp
			mov			ebp, esp
			mov			eax, [ebp + 12]			//����Ϊһ����ֵ
			mov			ecx, [ebp + 8]			//ecx��ʼָ��Ŀ�������ĩβ��ַ

		CONTINUE :
			xor				edx, edx					//Ϊ������׼��
			mov			esi, 14						//������Ϊ32λ
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
			inc				ecx					
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