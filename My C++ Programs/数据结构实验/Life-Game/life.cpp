#include<iostream>
#include"life.h"
using namespace std;

int Life::neighbour_count(int row, int col){
	int i,j;
	int count=0;
	for(i=row-1;i<=row+1;i++){
		for(j=col-1;j<=col+1;j++){
			count+=grid[i][j];		//incease the count if neighbour is alive.
		}
	}
	count-=grid[row][col];		//reduce count,since cell is not its own neighbour.
	return count;
}

void Life::initialize(){
	int row,col;
	for(row=0;row<=maxrow;row++)
		for(col=0;col<=maxcol;col++)
			grid[row][col]=0;
	cout<<"\nList the coordinates for living cells."<<endl;
	cout<<"Terminate the list with the special pair -1 -1"<<endl;
	cin>>row>>col;
	while(row!=-1||col!=-1){
		if(row>=1&&row<=maxrow)
			if(col>=1&&col<=maxcol)
				grid[row][col]=1;
			else
				cout<<"Column "<<col<<" is out of range."<<endl;
		else
			cout<<"Row "<<row<<" is out of range."<<endl;
		cin>>row>>col;
	}
}


void Life::print(){
	int row,col;
	cout<<"\nThe current Life configureation is: "<<endl;
	for(row=1;row<=maxrow;row++){
		for(col=1;col<=maxcol;col++)
			if(grid[row][col]==1) cout<<'*';
			else cout<<' ';
		cout<<endl;
	}
	cout<<endl;
}


void Life::update(){
	int row,col;
	int new_grid[maxrow+2][maxcol+2];
	for(row=1;row<=maxrow;row++)
		for(col=1;col<=maxcol;col++)
			switch(neighbour_count(row,col)){
			case 2:
				//new_grid[row][col]=1;
				new_grid[row][col]=grid[row][col];		//status stays the same
				break;
			case 3:
				new_grid[row][col]=1;			//cell is now alive
				break;
			default:
				new_grid[row][col]=0;			//cell is now dead
		}
		for(row=1;row<=maxrow;row++)
			for(col=1;col<=maxcol;col++)
				grid[row][col]=new_grid[row][col];
}


void instructions(){
	cout<<"Welcome to Conway's game of life."<<endl;
	cout<<"this game uses a grid of size "<<maxrow<<" by "<<maxcol<<" in which"<<endl;
	cout<<"each cell can either be occupied by an organism or not."<<endl;
	cout<<"The occupied cells change from generation to generation"<<endl;
	cout<<"according to the number of neighbouring cells which are alive."<<endl;
}