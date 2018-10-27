#ifndef INTOSUF
#define INTOSUF
#include<string>
#include<stdlib.h>		//其中的atof()函数可以自动读取下一个数值，包括浮点数

using namespace std;  //这里需要添加，同时包含这个头文件的cpp文件就不用了

class conversionUtils {
	private:
		static int index;
		static int lens;
		static double readNextDigit(string &s);
		static char preReadNextChar(string &s);
		static char readNextOper(string &s);
	public:
		static string conversion(string s);	//中缀转后缀,以#结束输入
};

#endif // not define INTOSUF
