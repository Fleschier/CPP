#include<iostream>
#include<stack>
#include<string>
#include<ctime>

using namespace std;
typedef int Error_code;

template<typename T>
Error_code copy_stack(stack<T> &dest,stack<T> &source){
	try{
		stack<T> tmp;
		while(!source.empty()){
			T t=source.top();
			source.pop();
			tmp.push(t);
		}
		while(!tmp.empty()){
			T t=tmp.top();
			tmp.pop();
			dest.push(t);
			source.push(t);
		}
		return (0);
	}
	catch(...){
		return (-1);
	}
}

template<typename T>
void showdata(stack<T> n){
	while (!n.empty()){
		cout<<n.top()<<endl;
		n.pop();		
	}
}

int main(){
	srand(time(0));
	stack<int> n;
	n.push(2);
	n.push(3);
	for(int i=0;i<10;i++){
		n.push(rand()%10);
	}
	stack<int> n2;
	copy_stack(n2,n);
	cout<<("n:\n");
	showdata(n);
	cout<<("---------------------------------------\n");
	cout<<("n2:\n");
	showdata(n2);

	return 0;
}