/*
��д�������������⣺
 E17.	�ֹ��ڳ�������Ŀ¼�´���1���ı��ļ�Data.txt��
 ���ļ��д����9��int���ݣ�������֮���Կո�����
 ��д1������ʹ���ļ�������ط���˳��������²�����
1)	��ȡ�ļ�Data.txt�е��������ݣ� 
2)	����ȡ�õ��������Զ����Ƶ���ʽ��ŵ���������Ŀ¼�µ��ļ�Res.dat�У�
3)	�ٴζ�ȡRes.dat�е��������ݣ�
4)	������Щ�������ı��ļ�����ʽ��ŵ���������Ŀ¼�µ�Res.txt�ļ��У�
���ʱÿ��2�����ݣ�ÿ������ռ10�У��Ҷ��룬��߲�'C'�ַ���
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
	ifstream in("Data.txt"); 
	ofstream bout("Res.dat",ios::binary);		//�Զ�����д��
	for(string str;getline(in,str);)
		bout<<str<<endl;							//��ȡʱ��ȥ�����з���д��ʱ��ȫ��
	bout.flush();
	bout.close();

	ifstream bin("Res.dat",ios::binary);
	ofstream out("Res.txt");
	vector<string> vcs;

	int count = 0;
	for (string str;getline(bin,str);) {
		stringstream sst;			//stringstream��
		sst << setw(10) << setfill('C') << right << str;		//��ʽ�����뵽stringstream��

		for (string tps; sst >> tps;) {		//��stringstream���и�ʽ��������д��vector
			vcs.push_back(tps);
			count++;
			if (count % 2 == 0)  vcs.push_back("\n");
		}
	}
	
	//��vector�н�����д���ļ�
	for (unsigned i = 0; i < vcs.size(); i++) {	
		if (vcs[i]!="\n")
		out << setw(10) << setfill('C') << right << vcs[i];
		else out << vcs[i];
	}
	out.flush();		//��ջ���
	out.close();	//�ͷ���Դ
	return 0;
}