#ifndef DI_GRAPH
#define DI_GRAPH
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class Entry>
class Vertex {
public:
	bool flg = false;
	Entry entry;
	vector<Vertex<Entry>*> neibor_vtx ;
	Vertex(Entry);
	void add_neibor(Entry, vector<Vertex<Entry>>&);
};

template<class Entry>
class Di_Graph {
public:
	vector<Vertex<Entry>> vtx_arr;
	void Graph_Create();
	void Neibor_add();
	int Find_index(Entry);
	void Depth_Traversal(Vertex<Entry>);
	void Width_Traversal(Vertex<Entry>);
	void refreash_vertexes();
};

template<class Entry>
Vertex<Entry>::Vertex(Entry ety) {
	entry = ety;
}

template<class Entry>
void Vertex<Entry>::add_neibor(Entry ety, vector<Vertex<Entry>>& vtx_arr) {
	int n = 0;
	for (int i = 0; i < vtx_arr.size(); i++) {
		if (vtx_arr[i].entry == ety) {
			n = i;
			break;
		}
	}
	this->neibor_vtx.push_back(&vtx_arr[n]);
}

template<class Entry>
int Di_Graph<Entry>::Find_index(Entry ety) {
	int n;
	for (int i = 0; i < vtx_arr.size(); i++) {
		if (vtx_arr[i].entry == ety) {
			n = i;
			break;
		}
	}
	return n;
}

template<class Entry>
void Di_Graph<Entry>::Neibor_add() {
	cout << "please enter a vertex you want to update(enter 'E' to stop):\n";
	string s;
	cin >> s;
	while (s != "E") {
		int n = this->Find_index(s);

		string desti;
		cout << "please enter all the neighbours for the vertex(end with 'X'):\n";
		cin >> desti;
		while (desti != "X") {
			this->vtx_arr[n].add_neibor(desti,vtx_arr);
			cin >> desti;
		}

		cout << "please enter a vertex you want to update(enter 'E' to stop):\n";
		cin >> s;
	}
}

template<class Entry>
void Di_Graph<Entry>::Graph_Create() {
	cout << "please enter the vertexes you'd like to add(enter 'E' to stop):\n";
	string s;
	cin >> s;
	while (s != "E") {
		vtx_arr.push_back(Vertex<Entry>(s));
		cin >> s;
	}

	this->Neibor_add();
}

template<class Entry>
void Di_Graph<Entry>::Depth_Traversal(Vertex<Entry> vtx) {
	cout << vtx.entry << "    ";
	vtx.flg = true;

	while (true) {
		int i = 0;//record the unvisited neighbour
		bool sign = true;
		while (vtx.neibor_vtx[i]->flg == true) {
			i++;
			if (i == vtx.neibor_vtx.size()) {
				sign = false;
				break;
			}
		}
		if (!sign) break;
		vtx = *(vtx.neibor_vtx[i]);
		cout << vtx.entry << "    ";
		vtx.flg = true;
	}

	//recursive traversal
	for (int i = 0; i < vtx_arr.size(); i++) {
		if (vtx_arr[i].flg == false) {
			Depth_Traversal(vtx_arr[i]);
			break;
		}
	}
}

template<class Entry>
void Di_Graph<Entry>::Width_Traversal(Vertex<Entry> vtx) {
	cout << vtx.entry << "    ";
	vtx.flg = true;
	int i = 0;
	for (int i = 0; i < vtx.neibor_vtx.size(); i++) {
		if (vtx.neibor_vtx[i]->flg == false) {
			cout << vtx.entry << "    ";
			vtx.neibor_vtx[i]->flg = true;
		}
	}
	//recursive traversal
	for (int i = 0; i < vtx_arr.size(); i++) {
		if (vtx_arr[i].flg == false) {
			Width_Traversal(vtx_arr[i]);
			break;
		}
	}
}

template<class Entry>
void Di_Graph<Entry>::refreash_vertexes() {
	for (int i = 0; i < vtx_arr.size(); i++) {
		vtx_arr[i].flg = false;
	}
}

#endif //!DI_GRAPH