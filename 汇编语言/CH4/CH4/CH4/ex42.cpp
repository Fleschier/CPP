#include<iostream>

int main() {
	printf("Please enter a string: ");
	char s1[100];
	scanf("%s", s1);
	printf("Please enter another one(had better be an substring of the previous one):");
	char s2[100];
	scanf("%s", s2);
	int idx = -1;			//s2��s1�г��ֵ���ʼλ�ã�Ĭ��Ϊ-1
	int len1, len2;			//������ַ����ĳ���
	len1 = strlen(s1);
	len2 = strlen(s2);

	_asm {
		lea			ESI, s1
		lea			EDI, s2
		mov		EDX, idx			//EDX�洢���ķ���ֵ

		//�Ƚ�s1��s2�ĳ��ȣ����s2��s1������ôs2һ������s1���Ӵ���ֱ�ӷ���-1
		mov		EAX, len1
		mov		EBX, len2
		cmp			EAX,EBX
		jL				QUIT

		mov		EAX, 0				//�����ڱ�������ǰѭ���˶��ٱ�
		mov		EBX, len1			//s1�ĳ���
		mov		ECX, len2				//����s2�ĳ��Ƚ���ѭ��
	NEXTLOOP:
		Inc			EAX			//EAX������������Ҫ����ECX=0����ת֮ǰ������������index��ֵ��1�����⣬���Ҳ��ܷ���dec ECX֮����Ϊ��Ӱ���־λ�����Է���ѭ����ʼ�Ͳ�����������
		cmpsb				//���ֽڱȽ�
		jnz			ISDIFF			//�����ǰλ�ַ���ͬ
		;
		//�����ͬ������Ƚ���һ���ַ�
	
		dec			ECX
		jz				END		//���ECX= 0��ѭ����������ʾÿһλ����ͬ
		;
		cmp			EAX, EBX			//���Ƿ��Ѿ���������s1
		je				END					//�����������s1���˳�
		;
		jmp			NEXTLOOP 			//������һ��ѭ��
		
	ISDIFF:			//����Ƚϵ��ַ�����ͬ
		lea 			EDI, s2			//��Ŀ���ַ�����ָ���˻���ʼλ��
		mov		ECX, len2		//ˢ��ѭ������
		jmp			NEXTLOOP		


	END:
		cmp			ECX, 0				//�Ƚ�ECX��0�Ĵ�С�����ECX��Ϊ0��˵���Ƿ�������ֹ�����ʾû���ҵ�ƥ����Ӵ�����ֱ���˳�
		jnz			QUIT
		;
		//�ҵ��Ӵ������
		mov		ECX, len2
		sub			EAX, ECX 
		mov		EDX, EAX			//����EAX��¼��ѭ���Ĵ������������ѭ����ȫ������EAX - len2����ҪѰ�ҵ�index
		mov		idx, EDX			

	QUIT :		//ֱ���˳������
	}

	printf("The index is (start from 0): %d\n", idx);
	return 0;
}