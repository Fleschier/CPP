#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class sct {
public:
	string s;
	int num;
	sct() {
		s = "NULL"; num = 0;
	}
	sct(string sr,int n){
		s = sr;  num = n;
	}
};

void show_data(vector<sct>& sc) {
	int count = 0;
	for (int i = 0; i < sc.size(); i++) {
		cout << sc[i].s << " : " << sc[i].num << "    ";
		count++;
		//if (count % 5 == 0) cout << endl;
		cout << endl;
	}
	cout << endl;
}

void add_word(string s,vector<sct>& vc) {
	bool flg = false;
	for (int i = 0; i < vc.size(); i++) {
		if (s == vc[i].s) {
			vc[i].num++;
			flg = true;
			break;
		}
	}
	if (!flg) {
		vc.push_back(sct(s, 1));
	}
}

void spilit_word(string s,vector<sct>& vc) {
	stringstream ss(s);
	string st;
	while (ss>>st) {
		add_word(st, vc);
	}
}

void swap(sct& a, sct& b) {
	sct tmp = a;
	a = b;
	b = tmp;
}

void sort(vector<sct>& sc) {
	//int mni;
	for (int i = 0; i < sc.size() - 1; i++) {
		int mni = i;
		for (int j = i + 1; j < sc.size(); j++) {
			if (sc[mni].num < sc[j].num) mni = j;
		}
		if (mni != i) swap(sc[i], sc[mni]);
	}

}

int main()
{
	ifstream infile;						//注意要使用名空间std，不然就要写成std::ofstream才行
	infile.open("test.txt");
	if (!infile.is_open()) {
		cout << "The file path is invalid or the file isn't exist ! please check ! \n";
		exit(-1);
	}

	string s;
	vector<sct> vc;
	//getline函数可以直接一行行地将数据读入string
	vc.push_back(sct());
	while (getline(infile, s)) {
		spilit_word(s, vc);
	}
	sort(vc);
	cout << "单词统计如下：\n";
	show_data(vc);
	//关闭文件释放资源
	infile.close();
	return 0;
}