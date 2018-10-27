//#ifndef SET_H
//#define SET_H
//
//#define MAX_SIZE 1000
////#include<iostream>
////using namespace std;
//
//enum Error_code { success, failed };
//template<typename Set_entry>
//class Set {
//	int count = 0;						//集合元素的个数，即指示数组的末尾在下标为n-1位置
//	Set_entry arr[MAX_SIZE];
//
//	//这里可以用哈希算法，将集合的元素存入哈希表里加快查找速率。但是对于小数据集，查找不是很频繁的没有必要。
//	//比如可以让 ASC(x)函数 返回x的ASCII码，新建一个 HASH[] 数组，x就存在 HASH[ASC(x)]的位置，查找时就直接查HASH[ASC(x)]。
//
//	void reset(int n);				//从数组的第n个下标开始，将后面每个元素向前移一位，用于删除元素后的操作。
//public :
//	int size();			//返回元素个数
//	Set();
//	Set(const Set<Set_entry>&);
//	Error_code add(const Set_entry&);		//增加元素
//	Error_code remove(const Set_entry&);	//删除元素
//	Set<Set_entry> Intersection(const Set<Set_entry>&);			//两集合的交集
//	Set<Set_entry> Union(const Set<Set_entry>&);					//两集合的并集
//	Set<Set_entry> Set_difference(const Set<Set_entry>&);		//两集合的差集
//
//	//friend ostream& operator<<(ostream& os, Set<Set_entry>& se) {			//输出函数重载（只能在类中实现）
//	//	int c = 0;
//	//	for (int i = 0; i < se.size(); i++) {
//	//		os << se.arr[i] << "   ";
//	//		c++;
//	//		if (c % 10 == 0) os << endl;
//	//	}
//	//	return os << endl;
//	//}
//} ;
//
//#endif // !SET_H