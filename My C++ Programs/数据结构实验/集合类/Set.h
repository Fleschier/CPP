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
//	int count = 0;						//����Ԫ�صĸ�������ָʾ�����ĩβ���±�Ϊn-1λ��
//	Set_entry arr[MAX_SIZE];
//
//	//��������ù�ϣ�㷨�������ϵ�Ԫ�ش����ϣ����ӿ�������ʡ����Ƕ���С���ݼ������Ҳ��Ǻ�Ƶ����û�б�Ҫ��
//	//��������� ASC(x)���� ����x��ASCII�룬�½�һ�� HASH[] ���飬x�ʹ��� HASH[ASC(x)]��λ�ã�����ʱ��ֱ�Ӳ�HASH[ASC(x)]��
//
//	void reset(int n);				//������ĵ�n���±꿪ʼ��������ÿ��Ԫ����ǰ��һλ������ɾ��Ԫ�غ�Ĳ�����
//public :
//	int size();			//����Ԫ�ظ���
//	Set();
//	Set(const Set<Set_entry>&);
//	Error_code add(const Set_entry&);		//����Ԫ��
//	Error_code remove(const Set_entry&);	//ɾ��Ԫ��
//	Set<Set_entry> Intersection(const Set<Set_entry>&);			//�����ϵĽ���
//	Set<Set_entry> Union(const Set<Set_entry>&);					//�����ϵĲ���
//	Set<Set_entry> Set_difference(const Set<Set_entry>&);		//�����ϵĲ
//
//	//friend ostream& operator<<(ostream& os, Set<Set_entry>& se) {			//����������أ�ֻ��������ʵ�֣�
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