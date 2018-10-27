#pragma once
#ifndef GRAPH
#define GRAPH
#include<iostream>

using namespace std;

template<class Entry>
class Vertex;

template<class Entry>
class Edge {
public:
	Vertex<Entry>* link_v;
	Edge<Entry>* next_e;
	Edge(Vertex<Entry>*);
};

template<class Entry>
class Vertex{
private:
	bool flg = false;
public:
	Entry entry;
	Edge<Entry>* next_e;
	Vertex<Entry>* next_v;
	Vertex(Entry);
};

template<class Entry>
class DiGraph{
private:
	void gen_vertex();
	void vtx_refresh();
public :
	//Vertex<Entry>* vtx_head;
	void Create_Edge(Entry, Entry);
	void Graph_create();
	void Depth_traversal(Vertex<Entry>*);
	void Width_traversal(Edge<Entry>*);
	Vertex<Entry>* vtx_arr[20];	//store all the vertexes link
};


template<class Entry>
Edge<Entry>::Edge(Vertex<Entry>* vtx) {
	link_v = vtx;
	next_e = NULL;
}

template<class Entry>
Vertex<Entry>::Vertex(Entry ety) {
	entry = ety;
	next_e = NULL;
}

template<class Entry>
void DiGraph<Entry>::Create_Edge( Entry from,Entry desti) {
	Vertex<Entry>* tmp = vtx_head;
	Vertex<Entry>* tp = vtx_head;
	while (tmp->entry != from) 
		tmp = tmp->next_v; //find the vertex correspond to the 'from'.
	while (tp->entry != desti) 
		tp = tp->next_v; //find the vertex correspond to the 'desti'.
	if (tmp->next_e != NULL) {
		Edge<Entry>* tmpe = tmp->next_e;
		while (tmpe->next_e != NULL) 
			tmpe = tmpe->next_e; //add the edge info to the end of the edge list.
		tmpe->next_e = new Edge<Entry>(tp);
	}
	else {
		tmp->next_e = new Edge<Entry>(tp);
	}

}

template<class Entry>
void DiGraph<Entry>::gen_vertex() {
	cout << "Please enter the vertexes your'd like to add to the graph(enter 'E' to stop):\n";
//	Vertex<Entry>* tmp = this->vtx_head;
	string s;
	int i = 0;
	cin >> s;
	this->vtx_arr[i] = new Vertex<Entry>(s);
	i++;
	while (s != "E") {
		cin >> s;
		this->vtx_arr[i] = new Vertex<Entry>(s);
		i++;
	}
}

template<class Entry>
void DiGraph<Entry>::Graph_create() {
	this->gen_vertex();//向将数据填入数组
	cout << "please enter the name of a vertex(enter 'E' to stop):\n";
	string from;
	cin >> from;
	while (from != "E") {

		cout << "please enter all the name of vertexes which is adjacent to the previous and split with space(enter 'X' as the end):\n";
		string s;
		cin >> s;
		if (s != "X") {
			this->Create_Edge(from, s);
			cin >> s;
		}
		while ( s != "X") {
			this->Create_Edge(from, s);
			cin >> s;
		}

		cout << "please enter the name of a vertex(enter 'E' to stop):\n";
		cin >> from;
	}
}

template<class Entry>
void DiGraph<Entry>::vtx_refresh() {
	for (int i = 0; i < 20; i++) {
		this->vtx_arr[i]->flg = false;
	}
}

template<class Entry>
void DiGraph<Entry>::Depth_traversal(Vertex<Entry>* vtxarr = NULL) {
	int n = 0;
	if (vtxarr == NULL) {
		vtxarr = vtx_arr[n];
		cout << (vtx_arr[n]->entry) << "     ";
	}
	//update the info of the array
	for (int i = 0; i < 20; i++)
		if(vtx_arr[i]->flg != false)
			if (vtx_arr[i]->entry == vtxarr->entry) {
				vtx_arr[i]->flg = false;
				break;
			}

	//depth traversal
	while(tmp->next_e->link_v != NULL) {
		tmp = tmp->next_e->link_v;
		cout << (tmp->entry) << "     ";
		//update the info of the array
		for (int i = 0; i < 20; i++)
			if (vtxarr[i] != NULL)
				if (vtxarr[i]->entry == tmp->entry) {
					vtxarr[i] = NULL;
					break;
				}
	}

	//recursive traversal
	for (int i = 0; i < 20; i++) {
		if (vtxarr[i] != NULL) {
			Depth_traversal(tmp, vtxarr);
			break;
		}
	}
}

template<class Entry>
void DiGraph<Entry>::Width_traversal(Edge<Entry>* tmp = NULL, Vertex<Entry>** vtxarr = NULL) {
	if (tmp == NULL) {
		cout << (vtx_head->entry) << "     ";
		tmp = vtx_head->next_e;
		cout << (tmp->link_v->entry) << "     ";
	}
	//update the info of the array
	for (int i = 0; i < 20; i++)
		if (vtxarr[i] != NULL)
			if (vtxarr[i]->entry == tmp->link_v->entry || vtxarr[i]->entry == vtx_head->entry) {
				vtxarr[i] = NULL;
				break;
			}

	//width traversal
	while (tmp->next_e != NULL) {
		tmp = tmp->next_e;
		cout << (tmp->link_v->entry) << "     ";
		//update the info of the array
		for (int i = 0; i < 20; i++) {
			Vertex<Entry>* tmp = NULL;
			if (vtxarr[i] != NULL)
				if (vtxarr[i]->entry == tmp->entry) {
					vtxarr[i] = NULL;
					break;
				}
		}
	}

	//recursive traversal
	for (int i = 0; i < 20; i++) {
		if (vtxarr[i] != NULL) {
			tmp = vtxarr[i]->next_e;
			Width_traversal(tmp, vtxarr);
			break;
		}
	}
}
#endif // !GRAPH
