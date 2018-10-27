#include<iostream>
#include<string>
#include<vector>
using namespace std;

string m[12]={"janurary","february","march","april","may","june","july","auguest","september","october","november","december"};
vector<string> mon(m,m+12);

int main()
{
	for(int k=0;k<3;++k){
		for(int i=0;i<mon.size()-1;++i){
			int tmp=i;
			for(int j=i+1;j<mon.size();++j){
				if(0==k) 
					if(mon[tmp][k]>mon[j][k])
						tmp=j;
				if(k>=1&&mon[tmp][k-1]==mon[j][k-1])
					if(mon[tmp][k]>mon[j][k])
						tmp=j;
			}
			if(tmp!=i){
				string ts=mon[i];mon[i]=mon[tmp];mon[tmp]=ts;
			}
		}
	}
	for(vector<string>::iterator itor=mon.begin();itor!=mon.end();++itor)
		cout<<*itor<<endl;
	return 0;
}