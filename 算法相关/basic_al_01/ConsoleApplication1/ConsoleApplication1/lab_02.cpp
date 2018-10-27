///*
//* P 008 1-2
//*/
//
//#include<iostream>
//#include<fstream>
//#include<assert.h>
//#include<string>
//#include<stdlib.h>
//using namespace std;
//
//int main() {
//	ifstream infile;
//	infile.open("1-2_input.txt");
//	assert(infile.is_open());		//断言，若失败则输出错误信息并终止程序
//
//	string s;
//	getline(infile, s);
//
///* atof()：将字符串转换为双精度浮点型值。
// * atoi()：将字符串转换为整型值。
// * atol()：将字符串转换为长整型值。
// */
//	int n = atoi(&s[0]);
//
//	int indexInfoArr[6] = { 0 };			//存储1位到6位字符串编码的起始值
//	indexInfoArr[0] = 1;
//	indexInfoArr[1] = 27;
//	indexInfoArr[2] = 27 + (25 + 1) * 25 / 2;
//	indexInfoArr[3] = indexInfoArr[2];
//
//	for (int i = 0; i < n; i++) {
//
//	}
//	cout << n << endl;
//	infile.close();			//关闭文件输入流
//	return 0;
//}
//
