//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> num;
//	cout << "please enter n:\n";
//	int n;
//	cin >> n;
//
//	for (int i = 0; i <= n - 1; i++) {
//		cout << "please enter a num:  ";
//		int tmp;
//		cin >> tmp;
//		num.push_back(tmp);
//	}
//	int count = 0;
//	for (int i = 0; i < num.size(); i++) {
//		cout << num[i] << "¡¡";
//		++count;
//		if (count % 10 == 0) cout << endl;
//	}
//	cout << endl;
//
//	reverse(num.begin(), num.end());
//	count = 0;
//	for (vector<int>::iterator itor = num.begin(); itor != num.end(); ++itor) {
//		cout << *itor << "  ";
//		++count;
//		if (count % 10 == 0) cout << endl;
//	}
//	cout << endl;
//	return 0;
//}