//#include<iostream>
//#include<string>
//using namespace std;
//
//int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//string date[7] = { "日","一","二","三","四","五","六" };
//
//int main()
//{
//	cout << "请输入月份和日期:\n";
//	int mon, day;
//	cin >> mon >> day;
//	int tot = day;
//	if (mon >= 2 && mon <= 12) {
//		for (int i = 1; i<mon; i++) {
//			tot += month[i - 1];
//		}
//		int tmp = tot % 7 - 1;
//		cout << "今天是星期" << date[tmp] << endl;
//	}
//	else if (mon == 1) cout << "今天是星期" << date[day % 7 - 1] << endl;
//
//	else cout << "error" << endl;
//
//	return 0;
//}