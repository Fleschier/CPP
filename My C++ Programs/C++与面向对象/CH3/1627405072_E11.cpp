//#include<iostream>
//#include<ctime>
//using namespace std;
//
//int num[10];
//
//int main()
//{
//	int i = 0;
//	srand(time(0));
//	while (i <= 9) {
//		num[i] = rand() % 100;
//		if (num[i] >= -9 && num[i] <= 9) {
//			i--;
//			continue;
//		}
//		else i++;
//	}
//	int max, min, sum=0;
//	max = min = num[0];
//	for (int j = 1; j <= 9; j++) {
//		sum += num[j];
//		if (num[j] >= max) max = num[j];
//		else if (num[j] <= min) min = num[j];
//		//cout << num[j] << endl;
//	}
//	double avg = 1.0 * sum / 10;
//	cout << "最大值为：" << max << endl << "最小值为：" << min << endl << "平均值为：" << avg << endl;
//	return 0;
//}