#include<iostream>
#include"life.h"
#include"utility.h"

using namespace std;

int main()
{
	Life configuration;
	instructions();
	configuration.initialize();

	configuration.print();
	cout<<"Continue viewing new generations?"<<endl;

	while(user_says_yes()){
		configuration.update();
		configuration.print();
		cout<<"Continue viewing new generations?"<<endl;
	}

	return 0;
}