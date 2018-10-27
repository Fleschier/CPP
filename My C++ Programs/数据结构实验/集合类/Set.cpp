//#include"Set.h"
//
//template<typename Set_entry>
//int Set<Set_entry>::size() {
//	return this->count;
//}
//
//template<typename Set_entry>
//Set<Set_entry>::Set() {
//	count = 0;
//}
//
//template<typename Set_entry>
//Set<Set_entry>::Set(const Set<Set_entry>& se) {
//	for (int i = 0; i < se.size(); i++) {
//		arr[i] = se.arr[i];
//		count++;
//	}
//}
//
//template<typename Set_entry>
//Error_code Set<Set_entry>::add(const Set_entry& se) {
//	bool flg = 0;
//	for (int i = 0; i < count; i++) 
//		if (arr[i] == se) {
//			flg = 1;
//			break;
//		}
//	if (flg) return success;
//
//	else if (count <= MAX_SIZE) {
//		arr[count - 1] = se;
//		count++;
//	}
//	else {
//		return failed;
//		exit(-1);
//	}
//	return success;
//}
//
//template<typename Set_entry>
//void Set<Set_entry>::reset(int n) {			//n为被删除元素的下标
//	for (int i = n; i < count; i++) {
//		this->arr[i] = this->arr[i + 1];
//	}
//	count--;
//}
//
//template<typename Set_entry>
//Error_code Set<Set_entry>::remove(const Set_entry& se) {
//	bool flg = 0;
//	for (int i = 0; i < count; i++) 
//		if (arr[i] == se) {
//			flag = 1;
//			this->reset(i);
//			break;
//		}
//
//	return (flg ? success : failed);
//}
//
//template<typename Set_entry>
//Set<Set_entry> Set<Set_entry>::Intersection(const Set<Set_entry>& s) {
//	Set<Set_entry> tpset;
//	int tmp = 0;
//	for (int i = 0; i < count; i++) 
//		for (int j = 0; j < s.size(); j++) {
//			if (arr[i] == s.arr[j]) {
//				tpset[tmp] = arr[i];			//这里没有使用add方法可以提高效率
//				tmp++;
//			}
//		}
//
//	return tpset;
//}
//
//template<typename Set_entry>
//Set<Set_entry> Set<Set_entry>::Union(const Set<Set_entry>& se) {
//	Set<Set_entry> tpset = Set(se);
//	for (int i = 0; i < count; i++) {
//		tpset.add(arr[i]);
//	}
//	return tpset;
//}
//
//template<typename Set_entry>
//Set<Set_entry> Set<Set_entry>::Set_difference(const Set<Set_entry>& se) {
//	Set<Set_entry> tpset;
//	bool flg=1;
//	for (int i = 0; i < count; i++) {
//		for (int j = 0; j < se.size(); j++) {
//			if (arr[i] == se.arr[j]) {
//				flg = 0;
//				break;
//			}
//		}
//		if (flg) {
//			tpset.add(arr[i]);
//		}
//	}
//}
//
////模板类的输出流重载不能在函数外，这相当于重新定义了一个模板类
////template<typename Set_entry>
////ostream& operator<<(ostream& os, Set<Set_entry>& se) {
////	int c = 0;
////	for (int i = 0; i < se.size(); i++) {
////		os << se.arr[i] << "   ";
////		c++;
////		if (c % 10 == 0) os << endl;
////	}
////	return os << endl;
////}