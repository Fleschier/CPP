//// 在书中，各种内部排序算法的时间复杂度分析结果只给出了算法执行时间的阶，或大概执行时间。
//// 试通过具体数据比较各种算法的关键字比较次数和记录移动次数，以取得直观感受。 
//// 要求： 
//// （1）编写程序创建一些整数文件用于排序。
//// 	创建的这些文件可以根据需要生成不同的长度，
//// 	如长度分别为20，200和2000，以正序、逆序、随机顺序的方式创建这些文件，
//// 	通过把所有这些测试数据保存在文件中（而不是每次在测试程序时用随机数生成），
//// 	可以使用同样的数据去测试不同的方法，因此会更易于比较这些方法的性能。 
//// （2）数据表采用顺序存储结构
//// 	实现插入排序，选择排序，希尔排序，归并排序，快速排序，堆排序等排序，
//// 	并对这些算法的实现效率进行比较和分析。 
//// （3）排序的指标包含：运行时间，比较次数，移动次数。
//
//#include<iostream>
//#include<string>
//#include<time.h>
//#include<fstream>
//
//using namespace std;
//
////创建文件
//void Creat_File(string sorted_num,string reversed_num ,string random_num,int n_num){
//
//	ofstream sorted_file(sorted_num);
//	ofstream reverse_file(reversed_num);
//	ofstream random_file(random_num);
//
//	if(sorted_file){
//		for(int i=0;i<n_num;i++){
//			int putinfile = 2 * i + 1;
//			sorted_file << putinfile << endl;
//		}
//		sorted_file.close();
//		cout << "成功创建有序数列文件！！！" << endl;
//	}
//	else{
//		printf("创建失败！\n");
//	}
//
//	if(reverse_file){
//		for(int i=0;i<n_num;i++){
//			int putinfile = n_num+1-i;
//			reverse_file<<putinfile<<endl;
//		}
//		reverse_file.close();
//		cout<<"成功创建逆序数列文件！！！"<<endl;
//	}
//	else{
//		printf("创建失败！\n");
//	}
//
//	if(random_file){
//		srand((int)time(0));
//		for(int i=0;i<n_num;i++){
//			int putinnum =	1+rand()%(2*n_num);
//			random_file<<putinnum<<endl;
//		}
//		random_file.close();
//		cout<<"成功创建乱序数列文件！！！"<<endl;
//	}
//	else{
//		printf("创建失败！\n");
//	}
//}
//
////读取文件
//void Read_File(string filename, int lst[]){
//	ifstream in(filename);
//	int i=0;
//	for (int a; in>>a;){
//		lst[i] = a;
//		i++;
//	}
//}
//
////插入排序
//void Insertion_Sort(int n,int lst[],int compare,int move){
//	int i ,j;
//	compare=0;move=0;
//	for(i=1;i<n-1;i++){
//		int temp = lst[i];
//		for(j=i;j>0&& lst[j-1]>temp;j--){
//			lst[j]=lst[j-1];	
//			compare+=1;
//			move+=1;	
//		}
//		lst[j] = temp;
//		move+=1;
//	}
//}
//
////选择排序
//void Selection_Sort(int n,int lst[],int compare,int move){
//	int min;
//	compare=0;move=0;
//	for(int i=0;i<n-1;i++){
//		min = i;
//		for(int j=i+1;j<n;j++){
//			if(lst[j]<lst[min]){
//				min=j;
//				compare+=1;
//			}
//		}
//		if(min!=i){
//			int temp = lst[i];
//			lst[i] = lst[min];
//			lst[min] = temp;
//			move+=1;
//		}
//	}
//}
//
////希尔排序
//void Shell_Sort(int n,int lst[],int compare,int move){
//	int D,P,i;
//	compare=0;move=0;
//	for(D=n/2; D>0; D/=2){
//		for(P=D; P<n; P++){
//			int temp = lst[P];
//			for (i=P; i>=D&&lst[i-D]>temp; i-=D){
//				lst[i] = lst[i-D];
//				compare+=1;
//				move+=1;
//			}
//			lst[i] = temp;
//			move+=1;
//		}
//	}
//}
//
////归并排序
//void Merge(int lst[],int tmp[],int Lpos,int Rpos,int RightEnd,int compare,int move){
//	//Lpos = start of left half, Rpos = start of right half
//	//LeftEnd = end of left half
//	int i, LeftEnd, NumElements, TmpPos;
//
//	LeftEnd = Rpos -1;
//	TmpPos = Lpos;
//	NumElements = RightEnd - Lpos + 1;
//
//	while( Lpos <= LeftEnd && Rpos <= RightEnd ){
//		if( lst[Lpos] <= lst[Rpos]){
//			tmp[ TmpPos++ ] = lst[Lpos++];
//			compare+=1;
//			move+=1;
//		}
//		else{
//			tmp[ TmpPos++ ] = lst[Rpos++];
//			move+=1;
//		}
//	}
//
//	while(Lpos <= LeftEnd ){
//		tmp[TmpPos++] = lst[Lpos++]; 
//		move+=1;
//	}
//	while(Rpos <= RightEnd){
//		tmp[TmpPos++] = lst[Rpos++];
//		move+=1;
//	}
//
//	//copy tmp back to lst
//	for(int i=0;i<NumElements;i++,RightEnd--)
//		lst[RightEnd] = tmp[RightEnd];
//}
//void Msort(int lst[],int tmp[],int L,int R,int compare,int move){
//	int Mid;
//	if(L<R){
//		Mid = (L+R)/2;
//		Msort(lst,tmp,L,Mid,compare,move);
//		Msort(lst,tmp,Mid+1,R,compare,move);
//		Merge(lst,tmp,L,Mid+1,R,compare,move);
//	}
//}
//void Merge_Sort(int n, int lst[],int compare,int move){
//	compare=0;move=0;
//	int *Tmp = new int(n);
//	if(Tmp != NULL){
//		Msort(lst,Tmp,0,n-1,compare,move);
//		free(Tmp);
//	}
//	else cout<<"空间不足";
//}
//
////快速排序
//int partition(int lst[],int low,int high){
//	int pivot,i,last_small;
//	swap(lst[low],lst[(low+high)/2]);
//	pivot = lst[low];
//	last_small = low;
//	for(i=low+1; i<=high; i++){
//		if(lst[i]<pivot){
//			last_small = last_small+1;
//			swap(lst[last_small],lst[i]);
//		}
//	}
//	swap(lst[low],lst[last_small]);
//	return lst[last_small];
//}
//void Swap(int *a,int *b){
//	int *temp = a;
//	a = b;
//	b = temp;
//}
//void recursive_quick_sort(int lst[],int low,int high,int compare,int move){
//	int pivot,i,j;
//	if(low<high){
//		pivot = partition(lst,low,high);
//		i = low; j = high -1;
//		for(;;){
//			while( lst[++i] < pivot){compare+=1;}
//			while( lst[--j] > pivot){compare+=1;}
//			if(i<j){
//				Swap(&lst[i],&lst[j]);
//				move+=1;
//			}
//			else 
//				break;
//		}
//		Swap(&lst[i],&lst[high-1]);
//		move+=1;
//		recursive_quick_sort(lst,low,pivot-1,compare,move);
//		recursive_quick_sort(lst,i+1,high,compare,move);
//	}
//}
//void Quick_Sort(int n, int lst[],int compare,int move){
//	compare=0;move=0;
//	recursive_quick_sort(lst,0,n-1,compare,move);
//}
//
////堆排序
//void insert_heap(int current,int low,int high,int lst[],int compare,int move){
//	int large;
//	large = 2*low+1;
//	while(large<=high){
//		if(large<high && lst[large]<lst[large+1]){
//			compare+=1;
//			large++;
//		}
//		if(current>lst[large]){
//			compare+=1;
//			break;
//		}
//		else{
//			lst[low] = lst[large];
//			low = large;
//			large = 2*low+1;
//			move+=1;
//		}
//	}
//	lst[low] = current;
//	move+=1;
//}
//void build_heap(int n,int lst[],int compare,int move){
//	int low;
//	for(low=n/2-1;low>=0;low--){
//		int current = lst[low];
//		insert_heap(current,low,n-1,lst,compare,move);
//	}
//}
//void Heap_Sort(int n, int lst[],int compare,int move){
//	int current,last_unsorted;
//	compare=0;move=0;
//	build_heap(n,lst,compare,move);
//	for(last_unsorted = n-1; last_unsorted>0; last_unsorted--){
//		current = lst[last_unsorted];
//		lst[last_unsorted] = lst[0];
//		move+=1;
//		insert_heap(current,0,last_unsorted-1,lst,compare,move);
//	}
//}
//
////打印列表
//void print(int n, int lst[]){
//	for(int i=0;i<n;i++){
//		cout<<lst[i]<<' ';
//	}
//	cout<<endl;
//}
//
//double RUNTIME(clock_t start, clock_t end){
//	return double((end-start)*10000/CLOCKS_PER_SEC)/10000;
//}
//void test(int n,int lst[]){
//	clock_t start,end;
//	int compare=0,move=0;
//
//	start = clock();
//	Insertion_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"插入排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//
//	start = clock();
//	Selection_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"选择排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//
//	start = clock();
//	Shell_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"希尔排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//
//	start = clock();
//	Merge_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"归并排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//
//	start = clock();
//	Quick_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"快速排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//
//	start = clock();
//	Heap_Sort(n,lst,compare,move);
//	end = clock();
//	cout<<"堆排序运行时间为:"<<RUNTIME(start,end)<<' '<<"比较次数为:"<<compare<<"次 "<<"移动次数为:"<<move<<"次 "<<endl;
//}
//
//int main(){
//	string sorted_num = "sorted_num.txt";
//	string reversed_num = "reversed_num.txt";
//	string random_num = "random_sort.txt";
//
//	int test_num =1;  //测试次数
//	cout<<"请输入测试次数:";
//	cin>>test_num;
//
//	while(test_num){
//		int n_num = 20;
//		cout<<"请输入文件存储整数的个数："<<endl;
//		cin>>n_num;
//		int *lst = new int(n_num+1);
//		Creat_File(sorted_num,reversed_num,random_num,n_num);
//		Read_File(reversed_num,lst);
//		test(n_num,lst);
//		test_num--;
//		delete lst;
//	}
//	return 0;
//}
