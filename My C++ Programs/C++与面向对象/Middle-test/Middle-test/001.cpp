//#include<iostream>
//#include<string>
//#include<fstream>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//typedef struct {
//	string a; //�洢A�еĵ���
//	string b; //�洢B�еĵ���
//	int cab; //�洢����a�͵���b�������ĵ��й�ͬ���ִ������ܺ�
//} unit;
//typedef struct {
//	string a; //A�еĵ���
//	int ca; //����a�������ĵ��г��ֵĴ����ܺ�
//}unita;
//
//void read_data(string filename,vector<unit>&  tp) {
//	unit tmp;
//	ifstream in(filename);
//	if (in.is_open()) {
//		string ts;
//		while (getline(in,ts)) {		//ע��˴�һ��Ҫ��getline()��Ȼ�����
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
//	//cout << "A�е��ʳ��ִ���ǰ20��" << endl;
//	//print_top_units(vunita);
//	//cout << "�����������ʲ��������" << wfn << endl;
//	//cal_probs(vunit, vunita, wfn);
//	return 0;
//}