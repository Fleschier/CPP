#include"DiGraph.h"
#include<string>
//#include<iostream>

using namespace std;

int main() {
	DiGraph<string> digp;
	digp.Graph_create();

	//Vertex<string>** vtxarr;
	//digp.get_vtx(vtxarr);
	cout << "the result of depth traversal:\n";
	digp.Depth_traversal(NULL, vtxarr);

	cout << "the result of width traversal:\n";
	digp.Width_traversal(NULL, vtxarr);

	return 0;
}