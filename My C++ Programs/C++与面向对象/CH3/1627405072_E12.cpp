//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//struct alpha {
//	char s;
//	int n;
//};
//vector<alpha> lst;
//
//int main()
//{
//	cout << "������һ�������ո��Ӣ�ĵ���(����С��200)��" << endl;
//	string chr;
//	cin >> chr;
//	for (unsigned int i = 0; i < size(chr);++i) {
//		if (lst.empty()) {
//			lst.push_back({ chr[i], 1 });				//�ô���������������ӽṹ��
//		}
//		else {
//			int tmp = 1;
//			for (unsigned int j = 0; j < lst.size(); ++j) 
//				if (lst[j].s == chr[i]) {
//					lst[j].n++;
//					tmp = 0;
//					break;
//				}
//			if (tmp) {
//				lst.push_back({ chr[i], 1 });
//			}
//		}
//	}
//	for (unsigned int i = 0; i < lst.size() - 1; ++i) {
//		unsigned int k=i;
//		for (unsigned int j = i + 1; j < lst.size(); ++j) {
//			if (lst[j].n > lst[k].n) k = j;						//����ıȽ���j��k������j��i����Ȼ������������
//		}
//		if (k != i) {
//			int t = lst[i].n; lst[i].n = lst[k].n; lst[k].n = t;
//			char ts = lst[i].s; lst[i].s = lst[k].s; lst[k].s = ts;
//		}
//	}
//
//	for (unsigned int i = 0; i < lst.size(); ++i) {
//		cout << lst[i].s << ":  " << lst[i].n << endl;
//	}
//	return 0;
//}