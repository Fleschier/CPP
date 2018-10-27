#include"Di_Graph.h"
#include<iostream>

using namespace std;

int main() {
	Di_Graph<string> dgph;
	dgph.Graph_Create();
	cout << "depth traversal:\n";
	dgph.Depth_Traversal(dgph.vtx_arr[0]);
	dgph.refreash_vertexes();
	cout << "width traversal:\n";
	dgph.Width_Traversal(dgph.vtx_arr[0]);
	return 0;
}