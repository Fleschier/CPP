#pragma once
#ifndef TREE_NODE
#define TREE_NODE
#define NULL 0

template<typename Entry>
class Tree_Node {
public:
	Entry info;
	Tree_Node<Entry> * left;
	Tree_Node<Entry> * right;
	//Tree_Node<class Entry> * father;
	Tree_Node();
	Tree_Node(const Entry  entry);
	void add(const Tree_Node<Entry>* next);//将一个节点增加到这个结点的子节点中

};


template<typename Entry>
Tree_Node<Entry>::Tree_Node() {
	info = NULL;
	this->left = NULL;
	this->right = NULL;
}

template<typename Entry>
Tree_Node<Entry>::Tree_Node(const Entry node) {
	info = node;
	this->left = NULL;
	this->right = NULL;
}

template<typename Entry>
void Tree_Node<Entry>::add(const Tree_Node<Entry>* next) {
	if (next.info > info) {
		if (right == NULL) right = next;
		else right->add(next);
	}
	else {
		if (left == NULL) left = next;
		else left->add(next);
	}
}

#endif  //!TREE_NODE