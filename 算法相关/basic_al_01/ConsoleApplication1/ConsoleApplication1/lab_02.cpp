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
//	assert(infile.is_open());		//���ԣ���ʧ�������������Ϣ����ֹ����
//
//	string s;
//	getline(infile, s);
//
///* atof()�����ַ���ת��Ϊ˫���ȸ�����ֵ��
// * atoi()�����ַ���ת��Ϊ����ֵ��
// * atol()�����ַ���ת��Ϊ������ֵ��
// */
//	int n = atoi(&s[0]);
//
//	int indexInfoArr[6] = { 0 };			//�洢1λ��6λ�ַ����������ʼֵ
//	indexInfoArr[0] = 1;
//	indexInfoArr[1] = 27;
//	indexInfoArr[2] = 27 + (25 + 1) * 25 / 2;
//	indexInfoArr[3] = indexInfoArr[2];
//
//	for (int i = 0; i < n; i++) {
//
//	}
//	cout << n << endl;
//	infile.close();			//�ر��ļ�������
//	return 0;
//}
//
