//#include<iostream>
//#include<string>
//using namespace std;
//
//int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//string date[7] = { "��","һ","��","��","��","��","��" };
//
//int main()
//{
//	cout << "�������·ݺ�����:\n";
//	int mon, day;
//	cin >> mon >> day;
//	int tot = day;
//	if (mon >= 2 && mon <= 12) {
//		for (int i = 1; i<mon; i++) {
//			tot += month[i - 1];
//		}
//		int tmp = tot % 7 - 1;
//		cout << "����������" << date[tmp] << endl;
//	}
//	else if (mon == 1) cout << "����������" << date[day % 7 - 1] << endl;
//
//	else cout << "error" << endl;
//
//	return 0;
//}