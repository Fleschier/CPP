#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;

int main() {
	clock_t begin, end;

	begin = clock();
	WinExec("D:\\Crs chen\\Computer programming\\Git Storage\\C_plus\\操作系统\\多线程矩阵乘法\\多线程矩阵乘法\\1627405072.exe", SW_SHOWNORMAL);
	end = clock();
	cout << "the running time is : " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}