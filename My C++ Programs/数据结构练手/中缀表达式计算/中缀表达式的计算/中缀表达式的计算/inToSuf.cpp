#include"inToSuf.h"
#include<stack>

double conversionUtils::readNextDigit(string &s) {
	double d = atof(&s[index]);
	index += to_string(d).length();			//to_string������C++11�������������Խ�int,long,double����ֵ����תΪstring
	return d;
}

char conversionUtils::preReadNextChar(string &s) {
	char c = s[index];
	return c;
}

char conversionUtils::readNextOper(string &s) {
	char c = s[index];
	index++;
	return c;
}

string conversionUtils::conversion(string s) {
	lens = s.length();		//The length of input string
	index = 0;
	stack<string> stknum;
	stack<string> stkoper;
	char c = preReadNextChar(s);
	while (c != '#') {
		if (isdigit(c)) {
			string stmp;
			double tmp = readNextDigit(s);
			stmp = to_string(tmp);
			stknum.push(stmp);
		}
		else {
			char op = readNextOper(s);
			//string s1(&op);	
			stkoper.push(string(&op));		//char* ����ֱ�Ӹ�ֵ��string����char����
		}
	}
}