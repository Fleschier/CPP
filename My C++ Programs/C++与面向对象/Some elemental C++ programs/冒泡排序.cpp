//#include<iostream>
//#include<vector>
//#include<ctime>
//using namespace std;
//
//void Sort(vector<int>&);
//void Swap(int&, int&);
//
////void Sort(vector<int> &Arr)
////{
////	int  min_inx;
////
////	for (unsigned i = 0; i<Arr.size() - 1; i++)
////	{
////		min_inx = i;
////		for (unsigned j = i + 1; j<Arr.size(); j++)
////		{
////			if (Arr[j]<Arr[min_inx])
////				min_inx = j;
////		}
////		if (min_inx != i)
////			Swap(Arr[i], Arr[min_inx]);
////	}
////}
//void Sort(vector<int>& Arr) {
//	int min_inx;
//	for (unsigned i = 0; i < Arr.size() - 1; i++) {
//		min_inx = i;
//		for (unsigned j = i + 1; j < Arr.size(); j++) {
//			if (Arr[j] < Arr[min_inx])  min_inx = j;
//		}
//		if (min_inx != i)  	Swap(Arr[i], Arr[min_inx]);		//ע��jֻ��һ���м����������ʱҪ��min_inx
//	}
//}
//
//void Swap(int& a, int& b) {
//	int t = a;
//	a = b;
//	b = t;
//}
//
//int main()
//{
//	vector<int> num;
//
//	srand(unsigned(time(0)));
//	for (int i = 1; i <= 10; ++i) {
//		num.push_back(rand() % 100);
//	}
//
//	cout << "����ǰ��\n";
//	for (vector<int>::iterator itor=num.begin(); itor != num.end(); ++itor) {
//		cout << *itor << '\t';
//	}
//	cout << endl;
//
//	Sort(num);
//
//	cout << "�����\n";
//	for (unsigned i = 0; i < num.size(); ++i) {
//		cout << num[i] << '\t';
//	}
//	cout << endl;
//
//	return 0;
//}