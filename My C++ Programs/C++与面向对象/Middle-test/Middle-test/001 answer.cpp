//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef struct
//{
//	string a; //存储A列的单词
//	string b; //存储B列的单词
//	int cab; //存储单词a和单词b在所有文档中共同出现次数的总和
//} unit;
//
//typedef struct
//{
//	string a; //A列的单词
//	int ca; //单词a在所有文档中出现的次数总和
//}unita;
//
//void read_data(const string &FName, vector<unit> &Res);
//void cal_counts(const vector<unit> &vunit, vector<unita> &vunita);
//void sort_units(vector<unit> &vunit);
//void sort_units(vector<unita> &vunita);
//void print_top_units(const vector<unita> &vunita);
//void cal_probs(const vector<unit> &vunit, const vector<unita> &vunita, const string &wfn);
//
//int main()
//{
//	string rfn = "data.txt";
//	string wfn = "prob.txt";
//	vector<unit> vunit;
//	vector<unita> vunita;
//
//	read_data(rfn, vunit);
//	cal_counts(vunit, vunita);
//	sort_units(vunit);
//	sort_units(vunita);
//	cout << "A列单词出现次数前20：" << endl;
//	print_top_units(vunita);
//	cout << "计算条件概率并输出到：" << wfn << endl;
//	cal_probs(vunit, vunita, wfn);
//
//	return 0;
//}
//
//void read_data(const string &FName, vector<unit> &Res)
//{
//	ifstream fin(FName);
//	unit t;
//	int i;															//循环变量设置在这里是为了下面的i可以在循环外使用
//
//	if (fin.good() == true)
//	{
//		while (fin.eof() == false)
//		{
//			fin >> t.a >> t.b >> t.cab;
//			if (fin.bad() == false && fin.fail() == false)
//			{
//				for (i = 0; i<Res.size(); i++)		//这个循环第一遍不会执行，因为此时Res.size=0，将直接跳到下面的if判断
//				{
//					if (Res[i].a == t.a && Res[i].b == t.b)
//					{
//						Res[i].cab += t.cab;
//						break;
//					}
//				}
//
//				if (i == Res.size())					//第一次是先执行这一句
//				{
//					Res.push_back(t);
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << FName << "文件读操作打开异常，请检查!" << endl;
//		exit(0);
//	}
//	fin.close();
//}
//
//void cal_counts(const vector<unit> &vunit, vector<unita> &vunita)
//{
//	int i, j;
//	unita temp;
//
//	for (i = 0; i<vunit.size(); i++)
//	{
//		for (j = 0; j<vunita.size(); j++)
//		{
//			if (vunit[i].a == vunita[j].a)
//			{
//				vunita[j].ca += vunit[i].cab;
//				break;
//			}
//		}
//		if (j == vunita.size())
//		{
//			temp.a = vunit[i].a;
//			temp.ca = vunit[i].cab;
//			vunita.push_back(temp);
//		}
//	}
//}
//
//bool Cmp(const unit &X, const unit &Y)		//设置bool排序比较函数
//{
//	return X.cab > Y.cab;					//从高到低排序
//}
//
//void sort_units(vector<unit> &vunit)
//{
//	sort(vunit.begin(), vunit.end(), Cmp);
//}
//
//bool Cmp1(const unita &X, const unita &Y)
//{
//	return X.ca > Y.ca;
//}
//
//void sort_units(vector<unita> &vunita)
//{
//	sort(vunita.begin(), vunita.end(), Cmp1);
//}
//
//void print_top_units(const vector<unita> &vunita)
//{
//	int i;
//
//	for (i = 0; i<vunita.size(); i++)
//	{
//		if (i == 20)
//			break;
//		cout << setw(10) << setfill('S') << vunita[i].a;
//		cout << setw(5) << setfill('$') << vunita[i].ca << endl;
//	}
//	cout << endl;
//}
//
//void cal_probs(const vector<unit> &vunit, const vector<unita> &vunita,
//	const string &wfn)
//{
//	int i, j;
//	double p;
//	ofstream fout(wfn);
//
//	if (fout.good() == false)
//	{
//		cout << wfn << "文件写操作打开异常，请检查!" << endl;
//		exit(0);
//	}
//
//	for (i = 0; i<vunit.size(); i++)
//	{
//		for (j = 0; j<vunita.size(); j++)
//		{
//			if (vunit[i].a == vunita[j].a)
//			{
//				p = (double)vunit[i].cab / (double)vunita[j].ca;
//				fout << vunit[i].a << "|||" << vunit[i].b << "|||" << p << endl;
//			}
//		}
//	}
//	fout.close();
//}
//
//
