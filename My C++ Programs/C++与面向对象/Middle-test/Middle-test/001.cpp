//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//typedef struct {
//	string a; //存储A列的单词
//	string b; //存储B列的单词
//	int cab; //存储单词a和单词b在所有文档中共同出现次数的总和
//} unit;
//typedef struct {
//	string a; //A列的单词
//	int ca; //单词a在所有文档中出现的次数总和
//}unita;
//
//void read_data(string filename,vector<unit>&  tp) {
//	unit tmp;
//	ifstream in(filename);
//	if (in.is_open()) {
//		string ts;
//		while (getline(in,ts)) {		//注意此处一定要用getline()不然会出错
//			stringstream sst(ts);
//			sst >> tmp.a >> tmp.b >> tmp.cab;
//			sst.clear();
//			tp.push_back(tmp);
//		}
//	}
//	else cout << "open file failed!\n";
//
//	for (vector<unit>::iterator itor = tp.begin(); itor!=tp.end();) {
//
//	}
//
//	for (unsigned i = 0; i <10; i++) {
//		cout << tp[i].a << "  " << tp[i].b << "  " << tp[i].cab << endl;
//	}
//}
//
//int main() {
//	string rfn = "data.txt";
//	string wfn = "d:\\prob.txt";
//	vector<unit> vunit;
//	vector<unita> vunita;
//	read_data(rfn, vunit);
//	//cal_counts(vunit, vunita);
//	//sort_units(vunit);
//	//sort_units(vunita);
//	//cout << "A列单词出现次数前20：" << endl;
//	//print_top_units(vunita);
//	//cout << "计算条件概率并输出到：" << wfn << endl;
//	//cal_probs(vunit, vunita, wfn);
//	return 0;
//}