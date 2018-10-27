//#include"Tree_Node.h"
//
//template<typename Entry>
//Tree_Node<Entry>::Tree_Node() {
//	info = NULL;
//	this->left = NULL;
//	this->right = NULL;
//}
//
//template<typename Entry>
//Tree_Node<Entry>::Tree_Node(const Entry node) {
//	info = node;
//	this->left = NULL;
//	this->right = NULL;
//}
//
//template<typename Entry>
//void Tree_Node<Entry>::add(const Tree_Node<Entry>* next) {
//	if (next.info > info) {
//		if (right == NULL) right = next;
//		else right->add(next);
//	}
//	else {
//		if (left == NULL) left = next;
//		else left->add(next);
//	}
//}