#include<iostream>

int main() {
	printf("Please enter a string: ");
	char s1[100];
	scanf("%s", s1);
	printf("Please enter another one(had better be an substring of the previous one):");
	char s2[100];
	scanf("%s", s2);
	int idx = -1;			//s2在s1中出现的起始位置，默认为-1
	int len1, len2;			//输入的字符串的长度
	len1 = strlen(s1);
	len2 = strlen(s2);

	_asm {
		lea			ESI, s1
		lea			EDI, s2
		mov		EDX, idx			//EDX存储最后的返回值

		//比较s1与s2的长度，如果s2比s1长，那么s2一定不是s1的子串，直接返回-1
		mov		EAX, len1
		mov		EBX, len2
		cmp			EAX,EBX
		jL				QUIT

		mov		EAX, 0				//设立哨兵，看当前循环了多少遍
		mov		EBX, len1			//s1的长度
		mov		ECX, len2				//按照s2的长度进行循环
	NEXTLOOP:
		Inc			EAX			//EAX的自增操作需要放在ECX=0的跳转之前，否则最后会有index的值少1的问题，并且不能放在dec ECX之后，因为会影响标志位。所以放在循环开始就不会有问题了
		cmpsb				//串字节比较
		jnz			ISDIFF			//如果当前位字符不同
		;
		//如果相同则继续比较下一个字符
	
		dec			ECX
		jz				END		//如果ECX= 0则循环结束，表示每一位都相同
		;
		cmp			EAX, EBX			//看是否已经遍历完了s1
		je				END					//如果遍历完了s1则退出
		;
		jmp			NEXTLOOP 			//进入下一次循环
		
	ISDIFF:			//如果比较的字符不相同
		lea 			EDI, s2			//将目的字符串的指针退回起始位置
		mov		ECX, len2		//刷新循环次数
		jmp			NEXTLOOP		


	END:
		cmp			ECX, 0				//比较ECX与0的大小，如果ECX不为0则说明是非正常终止，则表示没有找到匹配的子串，则直接退出
		jnz			QUIT
		;
		//找到子串的情况
		mov		ECX, len2
		sub			EAX, ECX 
		mov		EDX, EAX			//由于EAX记录了循环的次数，所以如果循环完全结束则EAX - len2就是要寻找的index
		mov		idx, EDX			

	QUIT :		//直接退出的情况
	}

	printf("The index is (start from 0): %d\n", idx);
	return 0;
}