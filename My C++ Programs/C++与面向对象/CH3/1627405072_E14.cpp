//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int arry[10] = { 13,24,35,46,57,35,79,35,93 };
//vector<int> v;
//
//int main()
//{
//	cout << "请输入一个数：" << endl;
//	int num;
//	cin >> num;
//	for (unsigned int i = 0; i < size(arry); i++) {
//		v.push_back(arry[i]);
//	}
//	v.push_back(num);
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); ++i) {
//		cout << v[i] << "  ";
//	}cout << endl;
//
//	for (vector<int>::iterator itor = v.begin(); itor != v.end(); ++itor) {
//		for (vector<int>::iterator it = itor + 1; it != v.end(); ) {
//			if (*itor == *it) {
//				it = v.erase(it);
//			}
//			else ++it;
//		}
//	}
//	for (int i = 0; i < v.size(); ++i) {
//		cout << v[i] << "  ";
//	}cout << endl;
//	return 0;
//}