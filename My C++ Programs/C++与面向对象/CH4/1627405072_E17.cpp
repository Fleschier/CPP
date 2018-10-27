/*
编写程序解决以下问题：
 E17.	手工在程序所在目录下创建1个文本文件Data.txt，
 该文件中存放了9个int数据，各数据之间以空格间隔。
 编写1个程序，使用文件流的相关方法顺序完成以下操作：
1)	读取文件Data.txt中的所有数据； 
2)	将读取得到的数据以二进制的形式存放到程序所在目录下的文件Res.dat中；
3)	再次读取Res.dat中的所有数据；
4)	并将这些数据以文本文件的形式存放到程序所在目录下的Res.txt文件中，
存放时每行2个数据，每个数据占10列，右对齐，左边补'C'字符。
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
	ofstream bout("Res.dat",ios::binary);		//以二进制写入
	for(string str;getline(in,str);)
		bout<<str<<endl;							//读取时会去掉换行符，写入时补全。
	bout.flush();
	bout.close();

	ifstream bin("Res.dat",ios::binary);
	ofstream out("Res.txt");
	vector<string> vcs;

	int count = 0;
	for (string str;getline(bin,str);) {
		stringstream sst;			//stringstream流
		sst << setw(10) << setfill('C') << right << str;		//格式化输入到stringstream流

		for (string tps; sst >> tps;) {		//将stringstream流中格式化的数据写回vector
			vcs.push_back(tps);
			count++;
			if (count % 2 == 0)  vcs.push_back("\n");
		}
	}
	
	//从vector中将数据写回文件
	for (unsigned i = 0; i < vcs.size(); i++) {	
		if (vcs[i]!="\n")
		out << setw(10) << setfill('C') << right << vcs[i];
		else out << vcs[i];
	}
	out.flush();		//清空缓存
	out.close();	//释放资源
	return 0;
}