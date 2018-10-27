//#include<iostream>
//#include<iomanip>
//
//using namespace std;
//
////定义生成数组的函数
//int* arr_gena(int * arr,int n){
//	for(int i=0;i < n;i++){
//		cout<<"请输入第"<<i+1<<"个元素:"<<endl;
//		cin>>arr[i];
//	}
//	return arr;
//}
//
////定义输出函数
//void show_data(int * ip, int n){
//	int count=0;
//	for(int i=0;i<n;i++){
//		cout << setw(5) << left << ip[i];
//		count++;
//		if(count%10==0) cout<<endl;
//	}
//	cout<<endl;
//}
//
////定义交换函数
//void swap(int *a,int *b){
//	int tmp;
//	tmp=*a;
//	*a=*b;
//	*b=tmp;
//}
//
//void perm(int  arr[], int k, int m){			//m=num-1
//	if (k >m){									//当K>m时，此时arr就是一个排列，将其输出
//		show_data(arr, ++m);
//	}
//	else{
//		for (int i = k; i <= m; i++){
//			swap(&arr[k], &arr[i]);		//交换第一个元素与第i个元素
//			perm(arr, k + 1, m);				//将第一个看做独立的前缀，将剩下的元素进行递归求全排列
//			swap(&arr[k], &arr[i]);		//将第一个元素再交换回来，以便进行下一次交换
//		}
//	}
//}
//
//int main(){
//	int num;
//	int arry[50];				//不能在函数中定义数组并返回，那样函数结束时数组也会被删除。
//	cout<<"请输入元素个数n(n<50):\n";
//	cin>>num;
//	int *arr;
//	arr=arr_gena(arry,num);
//	//show_data(arr,num);
//	perm(arr,0,num-1);
//
//	return 0;
//}