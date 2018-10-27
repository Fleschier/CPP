#include<iostream>			
#include<ctime>

using namespace std;

#define MAX_SIZE 1000

enum Error_code { success, failed };
template<typename Set_entry>
class Set {
	int count = 0;						//集合元素的个数，即指示数组的末尾在下标为n-1位置
	Set_entry arr[MAX_SIZE];

	//这里可以用哈希算法，将集合的元素存入哈希表里加快查找速率。但是对于小数据集，查找不是很频繁的没有必要。
	//比如可以让 ASC(x)函数 返回x的ASCII码，新建一个 HASH[] 数组，x就存在 HASH[ASC(x)]的位置，查找时就直接查HASH[ASC(x)]。

	void reset(int n);				//从数组的第n个下标开始，将后面每个元素向前移一位，用于删除元素后的操作。
public:
	int size();			//返回元素个数
	Set();
	Set(Set<Set_entry>&);
	Error_code add( Set_entry);		//增加元素
	Error_code remove(Set_entry);	//删除元素
	Set<Set_entry> Intersection( Set<Set_entry>&);			//两集合的交集
	Set<Set_entry> Union(Set<Set_entry>&);					//两集合的并集
	Set<Set_entry> Set_difference( Set<Set_entry>&);		//两集合的差集
	friend ostream& operator<<(ostream& os, Set<Set_entry>& se) {			//输出函数重载（只能在类中实现）
		int c = 0;
		for (int i = 0; i < se.size(); i++) {
			os << se.arr[i] << "   ";
			c++;
			if (c % 10 == 0) os << endl;
		}
		return os << endl;
	}
										
};

template<typename Set_entry>
int Set<Set_entry>::size() {
	return this->count;
}

template<typename Set_entry>
Set<Set_entry>::Set() {
	count = 0;
}

template<typename Set_entry>
Set<Set_entry>::Set( Set<Set_entry>& se) {
	for (int i = 0; i < se.size(); i++) {
		arr[i] = se.arr[i];
		count++;
	}
}

template<typename Set_entry>
Error_code Set<Set_entry>::add( Set_entry se) {
	bool flg = 0;
	for (int i = 0; i < count; i++)
		if (arr[i] == se) {
			flg = 1;
			break;
		}
	if (flg) return success;

	else if (count <= MAX_SIZE) {
		arr[count] = se;
		count++;
	}
	else {
		return failed;
		exit(-1);
	}
	return success;
}

template<typename Set_entry>
void Set<Set_entry>::reset(int n) {			//n为被删除元素的下标
	for (int i = n; i < count; i++) {
		this->arr[i] = this->arr[i + 1];
	}
	count--;
}

template<typename Set_entry>
Error_code Set<Set_entry>::remove(Set_entry se) {
	bool flg = 0;
	for (int i = 0; i < count; i++)
		if (arr[i] == se) {
			flag = 1;
			this->reset(i);
			break;
		}

	return (flg ? success : failed);
}

template<typename Set_entry>
Set<Set_entry> Set<Set_entry>::Intersection(Set<Set_entry>& s) {
	Set<Set_entry> tpset;
	int tmp = 0;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < s.size(); j++) {
			if (arr[i] == s.arr[j]) {
				tpset.add(arr[i]);
			}
		}

	return tpset;
}

template<typename Set_entry>
Set<Set_entry> Set<Set_entry>::Union( Set<Set_entry>& se) {
	Set<Set_entry> tpset = Set(se);
	for (int i = 0; i < count; i++) {
		tpset.add(arr[i]);
	}
	return tpset;
}

template<typename Set_entry>
Set<Set_entry> Set<Set_entry>::Set_difference( Set<Set_entry>& se) {
	Set<Set_entry> tpset;
	bool flg = 1;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < se.size(); j++) {
			if (arr[i] == se.arr[j]) {
				flg = 0;
				break;
			}
		}
		if (flg) {
			tpset.add(arr[i]);
		}
		else flg = 1;
	}
	return tpset;
}

 int main()
{
	srand(time(0));
	Set<int> si,si1;
	for (int i = 0; i < 20; i++) {
		si.add(rand() % 100);
		si1.add(i);
	}
	cout << "si:\n" << si;
	cout << "si1:\n" << si1;

	Set<int> si2(si);
	cout << "si2: \n" << si2;

	cout << "si和si1的交集：\n" << si.Intersection(si1);

	cout << "si和si1的并集：\n"<< si.Union(si1);

	cout << "si对si1的差集：\n" << si.Set_difference(si1);
	return 0;
}