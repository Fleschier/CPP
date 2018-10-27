//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<fstream>
//#include<sstream>
//#include<iomanip>
//
//using namespace std;
//
//typedef struct {
//	int id;
//	string name;
//	int age;
//	char sex;
//	vector<int> interest; //该向量存储用户的多个兴趣
//} User;
//
//string interests[4] = { "music","movie","reading","travel" };
//
//void read_data(string File, vector<User> & vec);
//void sort(vector<User>& vec);
//void print(vector<User>& vec);
//void myfilter(vector<User>& vec1, vector<User>& ,int ins);
//vector<User> myfilter(vector<User>& vec, int L=20, int  H=30);
//
//
//
//int main()
//{
//	string filename = "data2.txt";
//	vector<User> vec_user, vec_a, vec_b;
//	read_data(filename, vec_user);
//	sort(vec_user);
//	cout << "排序后用户信息：" << endl;
//	print(vec_user);
//	myfilter(vec_user, vec_a, 1);
//	cout << "对电影感兴趣的用户信息：" << endl;
//	print(vec_a);
//	vec_b = myfilter(vec_a, 22);
//	cout << "对电影感兴趣且年龄在22岁和30岁之间的用户信息：" << endl;
//	print(vec_b);
//	return 0;
//}
//
//void read_data(string File, vector<User> & vec) {
//	string tps;
//	User tpu;
//	int ins;
//	ifstream in(File);
//	while (getline(in, tps)) {
//		istringstream sst(tps);
//		sst >> tpu.id >> tpu.name >> tpu.age >> tpu.sex;
//		while (sst >> ins) {
//			tpu.interest.push_back(ins);
//		}
//		vec.push_back(tpu);												//不要忘了将处理好的单个元素送入向量
//		tpu.interest.clear();													//这里必须要清空interest这一向量
//	}
//}
//
//bool Cmp(User&us1, User& us2) {
//	if (us1.interest.size() == us2.interest.size())
//		return us1.age < us2.age;
//	else
//		return us1.interest.size()>us2.interest.size();
//}
//void sort(vector<User>& vec) {
//	sort(vec.begin(),vec.end(),Cmp);
//}
//
//
//void print(vector<User>& vec) {
//	for (unsigned i = 0; i < vec.size(); i++) {
//		cout << setw(5) << vec[i].id << right << setw(10) << vec[i].name;
//		cout << setw(3) << right << vec[i].age << setw(3) << right << vec[i].sex;
//		for (unsigned j = 0; j < vec[i].interest.size(); j++) {
//			cout << setw(10) << right << interests[j];
//		}
//		cout << endl;
//	}
//}
//
//void myfilter(vector<User>& vec1, vector<User>& vec2, int ins=0) {
//	for (unsigned i = 0; i < vec1.size(); i++) {
//		for (unsigned j = 0; j < vec1[i].interest.size(); j++) {
//			if (j == ins) {
//				vec2.push_back(vec1[i]);
//			}
//		}
//	}
//}
//
//vector<User> myfilter(vector<User>& vec, int L , int H ) {				//函数默认参数在声明和定义只能出现一次
//	vector<User>tmp;
//	for (unsigned i = 0; i < vec.size(); i++) {
//		if (vec[i].age >= L&&vec[i].age <= H) {
//			tmp.push_back(vec[i]);
//		}
//	}
//	return tmp;
//}