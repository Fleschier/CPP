#ifndef INTOSUF
#define INTOSUF
#include<string>
#include<stdlib.h>		//���е�atof()���������Զ���ȡ��һ����ֵ������������

using namespace std;  //������Ҫ��ӣ�ͬʱ�������ͷ�ļ���cpp�ļ��Ͳ�����

class conversionUtils {
	private:
		static int index;
		static int lens;
		static double readNextDigit(string &s);
		static char preReadNextChar(string &s);
		static char readNextOper(string &s);
	public:
		static string conversion(string s);	//��׺ת��׺,��#��������
};

#endif // not define INTOSUF
