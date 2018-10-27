//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "please enter N and K(N（10 <= N <= 50）, K（1 <= K <= 20）):" << endl;
//	int n, k, count = 0;
//	cin >> n >> k;
//	int sum = 0;
//	double prc = 200;
//	for (int i = 1; ; i++) {
//		sum += n;
//		prc *= (1.0 + k / 100.0);
//		if (sum >= prc) {
//			count = i;
//			break;
//		}
//		else if (i > 20) {
//			count = i;
//			cout << "impossible\n";
//			break;
//		}
//	}
//	if (count <= 20) cout << "第" << count << "年能买下房子\n";
//	return 0;
//}