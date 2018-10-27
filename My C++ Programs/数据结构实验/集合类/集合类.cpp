#include<iostream>			
#include<ctime>

using namespace std;

#define MAX_SIZE 1000

enum Error_code { success, failed };
template<typename Set_entry>
class Set {
	int count = 0;						//����Ԫ�صĸ�������ָʾ�����ĩβ���±�Ϊn-1λ��
	Set_entry arr[MAX_SIZE];

	//��������ù�ϣ�㷨�������ϵ�Ԫ�ش����ϣ����ӿ�������ʡ����Ƕ���С���ݼ������Ҳ��Ǻ�Ƶ����û�б�Ҫ��
	//��������� ASC(x)���� ����x��ASCII�룬�½�һ�� HASH[] ���飬x�ʹ��� HASH[ASC(x)]��λ�ã�����ʱ��ֱ�Ӳ�HASH[ASC(x)]��

	void reset(int n);				//������ĵ�n���±꿪ʼ��������ÿ��Ԫ����ǰ��һλ������ɾ��Ԫ�غ�Ĳ�����
public:
	int size();			//����Ԫ�ظ���
	Set();
	Set(Set<Set_entry>&);
	Error_code add( Set_entry);		//����Ԫ��
	Error_code remove(Set_entry);	//ɾ��Ԫ��
	Set<Set_entry> Intersection( Set<Set_entry>&);			//�����ϵĽ���
	Set<Set_entry> Union(Set<Set_entry>&);					//�����ϵĲ���
	Set<Set_entry> Set_difference( Set<Set_entry>&);		//�����ϵĲ
	friend ostream& operator<<(ostream& os, Set<Set_entry>& se) {			//����������أ�ֻ��������ʵ�֣�
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
void Set<Set_entry>::reset(int n) {			//nΪ��ɾ��Ԫ�ص��±�
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

	cout << "si��si1�Ľ�����\n" << si.Intersection(si1);

	cout << "si��si1�Ĳ�����\n"<< si.Union(si1);

	cout << "si��si1�Ĳ��\n" << si.Set_difference(si1);
	return 0;
}