//#include<iostream>
//#include<iomanip>
//
//using namespace std;
//
////������������ĺ���
//int* arr_gena(int * arr,int n){
//	for(int i=0;i < n;i++){
//		cout<<"�������"<<i+1<<"��Ԫ��:"<<endl;
//		cin>>arr[i];
//	}
//	return arr;
//}
//
////�����������
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
////���彻������
//void swap(int *a,int *b){
//	int tmp;
//	tmp=*a;
//	*a=*b;
//	*b=tmp;
//}
//
//void perm(int  arr[], int k, int m){			//m=num-1
//	if (k >m){									//��K>mʱ����ʱarr����һ�����У��������
//		show_data(arr, ++m);
//	}
//	else{
//		for (int i = k; i <= m; i++){
//			swap(&arr[k], &arr[i]);		//������һ��Ԫ�����i��Ԫ��
//			perm(arr, k + 1, m);				//����һ������������ǰ׺����ʣ�µ�Ԫ�ؽ��еݹ���ȫ����
//			swap(&arr[k], &arr[i]);		//����һ��Ԫ���ٽ����������Ա������һ�ν���
//		}
//	}
//}
//
//int main(){
//	int num;
//	int arry[50];				//�����ں����ж������鲢���أ�������������ʱ����Ҳ�ᱻɾ����
//	cout<<"������Ԫ�ظ���n(n<50):\n";
//	cin>>num;
//	int *arr;
//	arr=arr_gena(arry,num);
//	//show_data(arr,num);
//	perm(arr,0,num-1);
//
//	return 0;
//}