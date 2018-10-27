//#include<iostream>
//#include<time.h>
//#include<string>
//#include<fstream>
//using namespace std;
//
//struct cor{
//	int x,y,z;
//}n[1000];
//
//int main()
//{
//	srand(unsigned(time(0)));
//	for(int i=0;i<=999;i++){
//		n[i].x=rand();
//		n[i].y=rand();
//		n[i].z=rand();
//		//cout<<n[i].x<<endl<<n[i].y<<endl<<n[i].z<<endl;
//	}
//		ofstream outs("result.txt");
//
//	for(int i=0;i<=999;i++){
//		int tmp=1;
//		for(int j=0;j<i;j++){
//			if(n[i].x<=n[j].x&&n[i].y<=n[j].y&&n[i].z<=n[j].z ||(n[i].x==n[j].x&&n[i].y==n[j].y&&n[i].z==n[j].z)){
//				tmp=0;
//			}
//		}
//		for(int k=i+1;k<=999;k++){
//			if(n[i].x<=n[k].x&&n[i].y<=n[k].y&&n[i].z<=n[k].z ||(n[i].x==n[k].x&&n[i].y==n[k].y&&n[i].z==n[k].z)){
//				tmp=0;
//			}
//		}
//		if(tmp==1){
//			outs<<n[i].x<<"  "<<n[i].y<<"  "<<n[i].z<<endl;
//		}
//	}
//	ofstream out("input.txt");
//
//	for(int i=0;i<=999;i++){
//		out<<n[i].x<<"  "<<n[i].y<<"  "<<n[i].z<<endl;
//	}
//	return 0;
//}