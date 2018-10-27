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
//	string a; //�洢A�еĵ���
//	string b; //�洢B�еĵ���
//	int cab; //�洢����a�͵���b�������ĵ��й�ͬ���ִ������ܺ�
//} unit;
//
//typedef struct
//{
//	string a; //A�еĵ���
//	int ca; //����a�������ĵ��г��ֵĴ����ܺ�
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
//	cout << "A�е��ʳ��ִ���ǰ20��" << endl;
//	print_top_units(vunita);
//	cout << "�����������ʲ��������" << wfn << endl;
//	cal_probs(vunit, vunita, wfn);
//
//	return 0;
//}
//
//void read_data(const string &FName, vector<unit> &Res)
//{
//	ifstream fin(FName);
//	unit t;
//	int i;															//ѭ������������������Ϊ�������i������ѭ����ʹ��
//
//	if (fin.good() == true)
//	{
//		while (fin.eof() == false)
//		{
//			fin >> t.a >> t.b >> t.cab;
//			if (fin.bad() == false && fin.fail() == false)
//			{
//				for (i = 0; i<Res.size(); i++)		//���ѭ����һ�鲻��ִ�У���Ϊ��ʱRes.size=0����ֱ�����������if�ж�
//				{
//					if (Res[i].a == t.a && Res[i].b == t.b)
//					{
//						Res[i].cab += t.cab;
//						break;
//					}
//				}
//
//				if (i == Res.size())					//��һ������ִ����һ��
//				{
//					Res.push_back(t);
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << FName << "�ļ����������쳣������!" << endl;
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
//bool Cmp(const unit &X, const unit &Y)		//����bool����ȽϺ���
//{
//	return X.cab > Y.cab;					//�Ӹߵ�������
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
//		cout << wfn << "�ļ�д�������쳣������!" << endl;
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
