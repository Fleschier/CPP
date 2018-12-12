#include<iostream>
#include<ctime>
#define MAXSIZE 100
using namespace std;

//这里采用快速排序算法
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//Partition function**********************************
int partition(int Array[], int head, int rear){
	int nTemp = Array[rear];					//以末尾的元素作为分割元素
	int i = head - 1;
	for (int j = head; j<rear; j++){
		if (Array[j] <= nTemp){
			i++;
			if (i != j){
				swap(Array[i], Array[j]);
			}
		}
	}
	swap(Array[i + 1], Array[rear]);		//将分割元素换到i+1的位置
	return (i + 1);										//返回分割元素的位置

}

void quick_sort(int Array[], int head, int rear){
	if (head < rear){
		int nIndex = partition(Array, head, rear);
		quick_sort(Array, head, nIndex - 1);
		quick_sort(Array, nIndex + 1, rear);
	}
}

void show_data(int Array[]) {
	int count = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		cout << (Array[i]) << "  ";
		count++;
		if (count % 10 == 0) cout << endl;
	}
}

int main() {
	srand(time(0));
	int nums[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; i++) {
		nums[i] = rand() % 100;
		//nums[i] = 10-i;
	}
	cout << "before:" << endl;
	show_data(nums);
	quick_sort(nums, 0, MAXSIZE - 1);
	cout << "after:" << endl;
	show_data(nums);
	return 0;
}