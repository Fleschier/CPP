#include<stdio.h>
#include<time.h>
#include<vector>

using namespace std;  //vector template is in the name space std

void show(int arr[], int len);
//recursive style
void recursive_merge_sort(int arr[], int len);
void merge(int previous[], int left[], int len_l, int right[], int len_r);

//non-recursive style
void non_recur_merge_sort(int arr[], int len);
vector<int> non_recur_merge(vector<int> left, vector<int> right);

int main() {
	clock_t begin, end;
	int testArr[] = { 4,24,75,12,67547,243,12,6,43,67,74 };
	int num = sizeof(testArr) / sizeof(testArr[0]);		//elements of testArr

	begin = clock();

	//recursive_merge_sort(testArr, num);
	non_recur_merge_sort(testArr, num);

	end = clock();
	printf("The total sorting time is %f s\n", (double)(end - begin) / CLOCKS_PER_SEC);

	show(testArr, num);
	return 0;
}

//display the contains of a array
void show(int arr[], int len) {
	printf("the sorted arr is: ");
	for (int i = 0; i < len; i++)
		printf("%d  ", arr[i]);
	printf("\n");
}

//used for show vector elements
void show(vector<int> vec) {
	int len = vec.size();
	for (int i = 0; i < len; i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

//------------------------------------------------------------------------------------------------------------

//Recursive Merge Sort function------use pointer
void recursive_merge_sort(int arr[], int len) {
	int mid = len / 2;
	if (len < 2) return;

	//use keyword 'new' to create memory space for the array with the variable premeter
	int* left = new int[mid];
	int* right = new int[len - mid];

	//copy data from previous to new arr
	for (int i = 0; i < mid; i++) left[i] = arr[i];
	for (int j = mid; j < len; j++) *(right + j - mid) = arr[j];

	//recursive sort
	recursive_merge_sort(left, mid);
	recursive_merge_sort(right, len - mid);

	//merge two subarr
	merge(arr, left, mid, right, len - mid);

	//don't forget delete(use new and delete in pair to avoid memory loss)
	delete[] left;
	delete[] right;
}

//key function for the merge sort
void merge(int previous[], int left[], int len_l, int right[], int len_r) {
	int* lp = left;		//lp point to the head of the left subset
	int* rp = right;		//rp point to the head of the right subset
	while (lp < left + len_l && rp < right + len_r) {		//here the point usage is similiar to the index , should use '<' instread of '<=' or it would be wrong of the stack
		if (*(lp) >= *(rp)) {
			*(previous) = *(rp);
			previous++;		//move pointer to the next position
			rp++;	//point to next int to compare
		}
		else {
			*(previous++) = *(lp++);	//simplified writing style
		}
	}
	//if one of the subset is empty while the other one is not, dirctly copy the rest to the merge array because the subset is already sorted!
	while (lp < left + len_l) {
		*(previous++) = *(lp++);
	}
	while (rp < right + len_r) {
		*(previous++) = *(rp++);
	}
}

//-------------------------------------------------------------------------------------------------------------

//this is a non-recursive edition of merge sort, and it is bottom to top
void non_recur_merge_sort(int arr[], int len) {
	//i haven't work out how to store data without vector

	//both for the tmp and result usage, created from the int array
	vector<vector<int>> resVec;	
	//copy data from arr to vector
	for (int i = 0; i < len; i++) {
		vector<int> tmp;
		tmp.push_back(arr[i]);
		resVec.push_back(tmp);
	}

	vector<vector<int>> tmpVec(resVec);
	int idx = 0;

	//-----------------------------
	//next is the key part of the non_recursive_merge_sort function
JUDGE:
	//这里有个错误卡了很久，vector越界，而且是最后一步。现记录错误原因;
	//此处不能用resVec而要用tmpVec，因为最后一次循环结束后，tmpVec是一个元素，而resVec还是处于两个元素的状态，还未将
	//tmpVec的值赋给resVec，所以此时如果写成resVec则不会进入最终阶段，而是继续进入循环，导致越界。
	if (tmpVec.size() == 1) {
		for (int i = 0; i < len; i++)
			arr[i] = tmpVec[0][i];
		return;
	}
	else {
		//resVec.clear();
		resVec = vector<vector<int>>(tmpVec);			//update the resVec
		tmpVec.clear();
		idx = 0;
		if (resVec.size() % 2 == 0) {
			goto EVEN;
		}
		else {
			goto ODD;
		}
	}

EVEN:		//if the num of elements(vector<int>) is even
	while (idx < resVec.size() - 1) {
		tmpVec.push_back(non_recur_merge(resVec[idx], resVec[idx + 1]));
		idx += 2;
	}
	goto JUDGE;

ODD:		//if the num of elements is odd
	while (idx < resVec.size() - 2) {
		tmpVec.push_back(non_recur_merge(resVec[idx], resVec[idx + 1]));
		idx += 2;
	}
	tmpVec.push_back(resVec[resVec.size() - 1]);	//push the last element
	goto JUDGE;
}

//non-recursive merge function
vector<int> non_recur_merge(vector<int> left, vector<int> right) {
	int i = 0, j = 0;
	int l_len = left.size();
	int r_len = right.size();
	vector<int> res;

	while (i < l_len && j < r_len) {
		if (left[i] <= right[j]) {
			res.push_back(left[i++]);
		}
		else {
			res.push_back(right[j++]);
		}
	}
	while (i < l_len) res.push_back(left[i++]);
	while (j < r_len) res.push_back(right[j++]);

	return res;
}

//------------------------------------------------------------------------------------------------------------