#include<iostream>
#include<string>
#include<time.h>
#include<fstream>

using namespace std;


//�����ļ�
void Creat_File(string sorted_num, string reversed_num, string random_num, int n_num) {

	ofstream sorted_file(sorted_num);
	ofstream reverse_file(reversed_num);
	ofstream random_file(random_num);

	if (sorted_file) {
		for (int i = 0; i<n_num; i++) {
			int putinfile = 2 * i + 1;
			sorted_file << putinfile << endl;
		}
		sorted_file.close();
		cout << "�ɹ��������������ļ�������" << endl;
	}
	else {
		printf("����ʧ�ܣ�\n");
	}

	if (reverse_file) {
		for (int i = 0; i<n_num; i++) {
			int putinfile = n_num + 1 - i;
			reverse_file << putinfile << endl;
		}
		reverse_file.close();
		cout << "�ɹ��������������ļ�������" << endl;
	}
	else {
		printf("����ʧ�ܣ�\n");
	}

	if (random_file) {
		srand((int)time(0));
		for (int i = 0; i<n_num; i++) {
			int putinnum = 1 + rand() % (2 * n_num);
			random_file << putinnum << endl;
		}
		random_file.close();
		cout << "�ɹ��������������ļ�������" << endl;
	}
	else {
		printf("����ʧ�ܣ�\n");
	}
}

//��ȡ�ļ�
void Read_File(string filename, int lst[]) {
	ifstream in(filename);
	int i = 0;
	for (int a; in >> a;) {
		lst[i] = a;
		i++;
	}
}

//��������
void Insertion_Sort(int n, int lst[], int &compare, int &move) {
	int i, j;
	compare = 0; move = 0;
	for (i = 1; i<n - 1; i++) {
		int temp = lst[i];
		for (j = i; j>0 && lst[j - 1]>temp; j--) {
			lst[j] = lst[j - 1];
			compare += 1;
			move += 1;
		}
		lst[j] = temp;
		move += 1;
	}
}

//ѡ������
void Selection_Sort(int n, int lst[], int &compare, int &move) {
	int min;
	compare = 0; move = 0;
	for (int i = 0; i<n - 1; i++) {
		min = i;
		for (int j = i + 1; j<n; j++) {
			if (lst[j]<lst[min]) {
				min = j;
				compare += 1;
			}
		}
		if (min != i) {
			int temp = lst[i];
			lst[i] = lst[min];
			lst[min] = temp;
			move += 1;
		}
	}
}


//ϣ������
void Shell_Sort(int n, int lst[], int &compare, int &move) {
	int D, P, i;
	compare = 0; move = 0;
	for (int D = n / 2; D > 0; D /= 2) {
		for (P = D; P<n; P++) {
			int temp = lst[P];
			for (i = P; i >= D && lst[i - D]>temp; i -= D) {
				lst[i] = lst[i - D];
				compare += 1;
				move += 1;
			}
			lst[i] = temp;
			move += 1;
		}
	}
}

//�鲢����
void Merge(int lst[], int tmp[], int Lpos, int Rpos, int RightEnd, int &compare, int &move) {
	//Lpos = start of left half, Rpos = start of right half
	//LeftEnd = end of left half
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd) {
		if (lst[Lpos] <= lst[Rpos]) {
			tmp[TmpPos++] = lst[Lpos++];
			compare += 1;
			move += 1;
		}
		else {
			tmp[TmpPos++] = lst[Rpos++];
			move += 1;
		}
	}

	while (Lpos <= LeftEnd) {
		tmp[TmpPos++] = lst[Lpos++];
		move += 1;
	}
	while (Rpos <= RightEnd) {
		tmp[TmpPos++] = lst[Rpos++];
		move += 1;
	}

	//copy tmp back to lst
	for (int i = 0; i<NumElements; i++, RightEnd--)
		lst[RightEnd] = tmp[RightEnd];
}
void Msort(int lst[], int tmp[], int L, int R, int &compare, int &move) {
	int Mid;
	if (L<R) {
		Mid = (L + R) / 2;
		Msort(lst, tmp, L, Mid, compare, move);
		Msort(lst, tmp, Mid + 1, R, compare, move);
		Merge(lst, tmp, L, Mid + 1, R, compare, move);
	}
}
void Merge_Sort(int n, int lst[], int &compare, int &move) {
	compare = 0; move = 0;
	int *Tmp = new int[n];			//new���÷�����....Բ���Ż������쳣
	if (Tmp != NULL) {
		Msort(lst, Tmp, 0, n - 1, compare, move);
		free(Tmp);
	}
	else cout << "�ռ䲻��";
}

//��������
//�����������շ��ֳ��ֵ�����
//�������������쳣��stack overflow��ջ���
//����˵���Ƿָ�����ĵݹ�ջ���˵��µݹ�ʧ������ֱ���˳���
//�����������Լ�д��quick sort������ԭ����quick sort�����Կ����ȽϵĴ����ǳ��Ӵ�����������൱��������ѡȡ�ķָ�㲻��
//��д��quicksort��4000���ҵ�ʱ��ͻ����ջ�������ԭ����������Ϊ100�����鶼�����ջ������쳣��Ҳ��֪��Ϊʲô
int partition(int lst[], int low, int high) {
	int pivot, i, last_small;
	swap(lst[low], lst[(low + high) / 2]);
	pivot = lst[low];
	last_small = low;
	for (i = low + 1; i <= high; i++) {
		if (lst[i]<pivot) {
			last_small = last_small + 1;
			swap(lst[last_small], lst[i]);
		}
	}
	swap(lst[low], lst[last_small]);
	return lst[last_small];
}
void Swap(int *a, int *b) {		
	int *temp = a;
	a = b;
	b = temp;
}
void recursive_quick_sort(int lst[], int low, int high, int &compare, int &move) {
	int pivot, i, j;
	if (low<high) {
		pivot = partition(lst, low, high);
		i = low; j = high - 1;
		for (;;) {
			while (lst[++i] < pivot) { compare += 1; }
			while (lst[--j] > pivot) { compare += 1; }
			if (i<j) {
				Swap(&lst[i], &lst[j]);
				move += 1;
			}
			else
				break;
		}
		Swap(&lst[i], &lst[high - 1]);
		move += 1;
		recursive_quick_sort(lst, low, pivot - 1, compare, move);
		recursive_quick_sort(lst, i + 1, high, compare, move);
	}
}
//------------------------------------------------
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int partition_and_swap(int Array[], int head, int rear, int &compare, int &move) {
	int division = Array[rear];					//��ĩβ��Ԫ����Ϊ�ָ�Ԫ��
	int i = head - 1;
	for (int j = head; j<rear; j++) {
		if (Array[j] <= division) {
			i++;
			compare++;
			if (i != j) {
				swap(Array[i], Array[j]);
				compare++;
				move++;
			}
		}
	}
	swap(Array[i + 1], Array[rear]);		//���ָ�Ԫ�ػ���i+1��λ��
	move++;
	return (i + 1);										//���طָ�Ԫ�ص�λ��

}
void quick_sort(int Array[], int head, int rear,int &compare, int &move) {
	if (head < rear) {
		int nIndex = partition_and_swap(Array, head, rear, compare, move);
		quick_sort(Array, head, nIndex - 1, compare, move);
		quick_sort(Array, nIndex + 1, rear, compare, move);
	}
}
void Quick_Sort(int n, int lst[], int &compare, int &move) {
	compare = 0; move = 0;
	//recursive_quick_sort(lst, 0, n - 1, compare, move);
	quick_sort(lst, 0, n - 1, compare, move);
}

//������
void insert_heap(int current, int low, int high, int lst[], int &compare, int &move) {
	int large;
	large = 2 * low + 1;
	while (large <= high) {
		if (large<high && lst[large]<lst[large + 1]) {
			compare += 1;
			large++;
		}
		if (current>lst[large]) {
			compare += 1;
			break;
		}
		else {
			lst[low] = lst[large];
			low = large;
			large = 2 * low + 1;
			move += 1;
		}
	}
	lst[low] = current;
	move += 1;
}
void build_heap(int n, int lst[], int &compare, int &move) {
	int low;
	for (low = n / 2 - 1; low >= 0; low--) {
		int current = lst[low];
		insert_heap(current, low, n - 1, lst, compare, move);
	}
}
void Heap_Sort(int n, int lst[], int &compare, int move) {
	int current, last_unsorted;
	compare = 0; move = 0;
	build_heap(n, lst, compare, move);
	for (last_unsorted = n - 1; last_unsorted>0; last_unsorted--) {
		current = lst[last_unsorted];
		lst[last_unsorted] = lst[0];
		move += 1;
		insert_heap(current, 0, last_unsorted - 1, lst, compare, move);
	}
}


//��ӡ����
void print(int n, int lst[]) {
		for (int i = 0; i<n; i++) {
		cout << lst[i] << ' ';
	}
	cout << endl;
}

double RUNTIME(clock_t start, clock_t end) {
	return double((end - start) * 100000 / CLOCKS_PER_SEC) / 100000;
}

void test(int n, int lst[]) {
	clock_t start, end;
	int compare = 0, move = 0;

	start = clock();
	Insertion_Sort(n, lst, compare, move);
	end = clock();
	cout << "������������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;

	start = clock();
	Selection_Sort(n, lst, compare, move);
	end = clock();
	cout << "ѡ����������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;

	start = clock();
	Shell_Sort(n, lst, compare, move);
	end = clock();
	cout << "ϣ����������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;

	start = clock();
	Merge_Sort(n, lst, compare, move);
	end = clock();
	cout << "�鲢��������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;

	start = clock();
	Quick_Sort(n, lst, compare, move);
	end = clock();
	cout << "������������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;

	start = clock();
	Heap_Sort(n, lst, compare, move);
	end = clock();
	cout << "����������ʱ��Ϊ:" << RUNTIME(start, end) << ' ' << "�Ƚϴ���Ϊ:" << compare << "�� " << "�ƶ�����Ϊ:" << move << "�� " << endl;


}


int main() {
	string sorted_num = "sorted_num.txt";
	string reversed_num = "reversed_num.txt";
	string random_num = "random_sort.txt";

	int test_num = 0;  //���Դ���		//��ֵΪ1Ҳ�ᱻ���ǵ���û������
	cout << "��������Դ���:";
	cin >> test_num;

	while (test_num) {
		int n_num = 0;			//??���ȸ�ֵΪ20��ȫû�����壬�ᱻ�����cin���ǵ���
		cout << "�������ļ�Ҫ�洢�������ĸ�����" << endl;
		cin >> n_num;
		int *lst = new int[n_num + 1];			//new�������������÷����Ų���Բ���š�����������
		Creat_File(sorted_num, reversed_num, random_num, n_num);
		Read_File(reversed_num, lst);
		test(n_num, lst);	
		test_num--;
		delete[] lst;			//// �ͷ��������飬new�����[] ��deleteҲ��Ҫ��[]
	}
	/*int m = 0, n = 0;
	int testArr []= { 34,12,645,12,4,1,65,2354,23,354,5,576567,57,46,34,2,13,54,46,67,67,4,53,42,31,451,5475,7,7888,132 };
	Quick_Sort(30, testArr, m, n);
	print(30, testArr);*/

	return 0;
}
