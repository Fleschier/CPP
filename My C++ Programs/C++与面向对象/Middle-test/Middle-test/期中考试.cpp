#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<sstream>

using namespace std;

void ReadFile(string FName, vector<string>& A);			// ���ļ�
void ShowData(vector<string>& A, int X = 5, int Y = 15);	// ��ʾ�����ڵ��ַ���
void ShowData(vector<int>& B, int X = 5, int Y = 8);		// ��ʾ�����ڵ�����
vector<int> GetNumbers(const vector<string>& A);		// ��ȡ����
void SortData(vector<int>& B);							// ����
void WriteFile(string FName, const vector<int>& B);		// д�ļ�

bool Cmp(int, int);

void ReadFile(string FName, vector<string>& A) {
	ifstream in(FName);
	if (in.good()) {
		string ts;
		while (in >> ts)
			A.push_back(ts);
	}
	else {
		cout << "File open failed!" << endl;
		exit(0);
	}
}

void ShowData(vector<string>& A, int X, int Y) {
	int count = 0;
	for (unsigned i = 0; i<A.size(); i++) {
		cout << setw(Y) << left << setfill(' ') << A[i];
		count++;
		if (count % X == 0)
			cout << endl;
	}
}

vector<int> GetNumbers(const vector<string>& A) {
	vector<int> tmp;
	int t;
	for (unsigned i = 0; i<A.size(); i++) {
		int flag = 1;
		for (unsigned j = 0; j<A[i].size(); j++) {
			if ((A[i][j] >= 65 && A[i][j] <= 90 || A[i][j] >= 96 && A[i][j] <= 122))
				flag = 0;
		}
		if (flag) {
			stringstream sst(A[i]);
			sst >> t;
			tmp.push_back(t);
		}
	}
	return tmp;
}

void ShowData(vector<int>& B, int X, int Y) {
	int count = 0;
	for (unsigned i = 0; i<B.size(); i++) {
		cout << setw(Y) << left << setfill(' ') << B[i];
		count++;
		if (count % X == 0)
			cout << endl;
	}
}

void SortData(vector<int>& B) {
	sort(B.begin(), B.end(), Cmp);
}

double Judge(int a) {
	int sum = 0, count = 0;
	int t;
	while (a != 0) {
		t = abs(a % 10);
		a /= 10;
		sum += t;
		count++;
	}
	return 1.0*sum / count;
}

bool Cmp(int a, int b) {
	return Judge(a)<Judge(b);
}

void WriteFile(string FName, const vector<int>& B) {
	ofstream out(FName);
	int count = 0;
	for (unsigned i = 0; i<B.size(); i++) {
		out << setw(5) << right << setfill('s') << B[i];
		count++;
		if (count % 4 == 0) {
			out << '\n';
		}
	}
}

void main()
{
	string ifname = "d:\\input.txt", ofname = "d:\\result.txt";
	vector<string> A;
	vector<int> B;

	ReadFile(ifname, A);

	cout << "�ļ���ȡ������ɺ��A����Ϊ:" << endl;
	ShowData(A);
	cout << endl;

	B = GetNumbers(A);
	cout << "������ȡ������ɺ��B����Ϊ:" << endl;
	ShowData(B);
	cout << endl;

	SortData(B);
	cout << "���������ɺ��B����Ϊ:" << endl;
	ShowData(B, 6);
	cout << endl;

	WriteFile(ofname, B);
}
