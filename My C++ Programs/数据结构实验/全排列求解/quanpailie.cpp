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
			cout<<"�������"<<i+1<<"��Ԫ��:"<<endl;
			cin>>arr[i];
		}
		return arr;
}

void perm(int *arr,int head,int rear) {		//rear=num
	if (head == rear-1) {
		show_nums(arr, rear);
	}
	else {
		for (int i = head; i < rear; i++) {				//ע��˴�i��head��ʼ����Ȼ����һ��ѭ��
			swap(arr[head], arr[i]);
			perm(arr, head + 1, rear);				//���ܴ����rearֵ��ô�䣬ֻ�������rear���øģ�������ĵݹ麯������ʽһ�£���Ϊ�ݹ飡����
			swap(arr[head], arr[i]);
		}
	}
}

int main() {
	int num;
	int arry[50];				//�����ں����ж������鲢���أ�������������ʱ����Ҳ�ᱻɾ����
	cout<<"������Ԫ�ظ���n(n<50):\n";
	cin>>num;
	int *arr;
	arr=arr_gena(arry,num);
	perm(arr,0,num);
	
	return 0;
}