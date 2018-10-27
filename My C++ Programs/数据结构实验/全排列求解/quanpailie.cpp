#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	int ti;
	ti = a;
	a = b;
	b = ti;
}

void show_nums(int* arr,int num) {
	int count = 0;
	for (int i = 0; i < num; i++) {
		cout << arr[i]<<"!";
		count++;
		if (count %10== 0) cout << endl;
	}
	cout << endl;
}

int* arr_gena(int *arr, int n) {
	for (int i = 0; i < n; i++) {
			cout<<"请输入第"<<i+1<<"个元素:"<<endl;
			cin>>arr[i];
		}
		return arr;
}

void perm(int *arr,int head,int rear) {		//rear=num
	if (head == rear-1) {
		show_nums(arr, rear);
	}
	else {
		for (int i = head; i < rear; i++) {				//注意此处i从head开始，不然会少一次循环
			swap(arr[head], arr[i]);
			perm(arr, head + 1, rear);				//不管传入的rear值怎么变，只有这里的rear不用改，与最初的递归函数的形式一致，因为递归！！！
			swap(arr[head], arr[i]);
		}
	}
}

int main() {
	int num;
	int arry[50];				//不能在函数中定义数组并返回，那样函数结束时数组也会被删除。
	cout<<"请输入元素个数n(n<50):\n";
	cin>>num;
	int *arr;
	arr=arr_gena(arry,num);
	perm(arr,0,num);
	
	return 0;
}