#include"Binary_Tree.h"
#include<iostream>

//===============================================
/*C++中，使用模板编程的时候，声明和实现都要写在头文件中，
如果实现不在头文件中，就会出现链接的时候，找不到符号的情况。
把实现都放到头文件中去，应该就没什么问题了。*/
//=================================================
using namespace std;

//
//
//template<typename Entry>
//class Tree_Node {
//public:
//	Entry info;
//	Tree_Node<Entry> * left;
//	Tree_Node<Entry> * right;
//	//Tree_Node<class Entry> * father;
//	Tree_Node();
//	Tree_Node(const Entry  entry);
//	void add(const Tree_Node<Entry>* next);//将一个节点增加到这个结点的子节点中
//
//};
//
//
//template<typename Entry>
//class Binary_Tree {
//public:
//	Binary_Tree();
//	Binary_Tree(Entry pre_arr[], Entry in_arr[], int size);//以两个序列创建树
//	void create_by_preorder_and_inorder();
//	void recursive_create(Tree_Node<Entry>* &sub_root, vector<Entry> &preorder, vector<Entry> &inorder);
//	Tree_Node<Entry>* Create_Tree(Entry&);
//	int cal_two_degree_nodes(Tree_Node<Entry>*, int);//计算度数为2的节点的个数
//	int cal_width();//统计二叉树的宽度
//	int find_degree(Tree_Node<Entry>*);//返回指定节点所在的层次
//	bool is_binary_search_tree();//判断是不是二分查找树
//	Tree_Node<Entry> * root = NULL;
//};
//
//
//
//
//
//
//
//
//template<typename Entry>
//Binary_Tree<Entry>::Binary_Tree() {
//	this->root = NULL;
//}
//
//template<typename Entry>
//Binary_Tree<Entry>::Binary_Tree(Entry pre_arr[], Entry in_arr[], int size) {
//	Tree_Node<Entry>* curr_root = pre_arr[0];
//	if (Root == NULL) Root = curr_root;
//	int left_len = 0;
//	int right_len = 0;
//
//	int inx_root = 0;
//	for (int i = 0; i < size; i++) {
//		left_len++;
//		if (in_arr(i) == pre_arr[0]) {
//			inx_root = i;
//			break;
//		}
//	}
//
//	Entry split = in_arr(inx_root - 1);
//	int inx_split = 0;
//	for (i = 0; i < size; i++) {
//		if (pre_arr(i) == split) {
//			inx_split = i;
//			break;
//		}
//	}
//
//
//}
//
//template<typename Entry>
//void Binary_Tree<Entry>::create_by_preorder_and_inorder() {
//	int n;
//	Entry temp;
//	vector<Entry> preorder, inorder;                     // store the user input;
//
//	cout << "Please enter the size of the tree:\n";
//	cin >> n;
//
//	cout << "Please enter a  preorder sequence, separated by spaces:\n";
//	for (int i = 0; i < n; i++) {
//		cin >> temp;
//		preorder.push_back(temp);
//	}
//	cout << "Please enter an inorder sequence, separated by spaces:\n";
//	for (int i = 0; i < n; i++) {
//		cin >> temp;
//		inorder.push_back(temp);
//	}
//	recursive_create(this->root, preorder, inorder);
//	return;
//}
//
//
//template<typename Entry>
//void Binary_Tree<Entry>::recursive_create(Tree_Node<Entry>* &sub_root, vector<Entry> &preorder, vector<Entry> &inorder) {
//	int len_pre = preorder.size(), len_in = inorder.size();
//	// 递归边界
//	if (!len_in || !len_pre) {
//		sub_root = NULL;
//		return;
//	}
//
//	// 先序序列的首元素一定是根节点
//	sub_root = new Tree_Node<Entry>(preorder[0]);
//	int in = 0;
//	// 找到根节点在中序序列中的下标
//	while (preorder[0] != inorder[in])
//		in++;
//	// 复制后便可以删除首元素
//	preorder.erase(preorder.begin());
//
//	// 迭代器
//	vector<Entry>::iterator it_in = inorder.begin();
//	// 两个临时向量，存放将inorder拆分后的两个序列
//	vector<Entry> inorder_left, inorder_right;
//	// 按照之前找到的根节点的下标将序列拆分并赋值
//	if (in != 0) {
//		inorder_left = vector<Entry>(it_in, it_in + in);   // vector的构造函数，it_in存的是inorder的首元素的下标
//	}
//	if (in != len_in - 1) {
//		inorder_right = vector<Entry>(it_in + in + 1, inorder.end());
//	}
//	// 递归调用
//	recursive_create(sub_root->left, preorder, inorder_left);
//	recursive_create(sub_root->right, preorder, inorder_right);
//	return;
//
//}
//
//template<typename Entry>
//int Binary_Tree<Entry>::cal_two_degree_nodes(Tree_Node<Entry>* tree_node , int count = 0) {
//	if (tree_node->left != NULL && tree_node->right != NULL) { 
//		count++; 
//		cal_two_degree_nodes(tree_node->left, count);
//		cal_two_degree_nodes(tree_node->right, count);
//	}
//	else {
//		if (tree_node->left != NULL) cal_two_degree_nodes(tree_node->left, count);
//		else if (tree_node->right != NULL) cal_two_degree_nodes(tree_node->right, count);
//	}
//	return count;
//}
//
//template<typename Entry>
//int Binary_Tree<Entry>::cal_width() {
//	int width = 0;
//	Tree_Node<Entry>* l_tree_node = this->root;
//	Tree_Node<Entry>* r_tree_node = this->root;
//	while (l_tree_node->left != NULL) {
//		width++;
//		l_tree_node = l_tree_node->left;
//	}
//	while (r_tree_node->right != NULL) {
//		width++;
//		r_tree_node = r_tree_node->right;
//	}
//	return width;
//}
//
//template<typename Entry>
//int Binary_Tree<Entry>::find_degree(Tree_Node<Entry>* tn) {
//	int depth = 0;
//	Tree_Node<Entry>* tree_node = this->root;
//	while (tn->info != tree_node->info) {
//		depth++;
//		if (tn->info <= tree_node->info) tree_node = tree_node->left;
//		else tree_node = tree_node->right;
//	}
//	return depth;
//}
//
//template<typename Entry>
//bool Binary_Tree<Entry>::is_binary_search_tree() {
//	Tree_Node<Entry>* l_tree_node = this->root;
//	Tree_Node<Entry>* r_tree_node = this->root;
//	bool flg = true;
//
//	while (l_tree_node->left != NULL) {
//		if (l_tree_node->left->info > l_tree_node->info) {
//			flg = false;
//			return flg;
//		}
//		l_tree_node = l_tree_node->left;
//	}
//
//	while (r_tree_node->right != NULL) {
//		if (r_tree_node->right->info <= r_tree_node->info) {
//			flg = false;
//			return flg;
//		}
//	}
//	return flg;
//}
//
//template<typename Entry>
//Tree_Node<Entry>* Binary_Tree<Entry>::Create_Tree(Entry& entry = NULL) {
//	Tree_Node<Entry>*  current = new Tree_Node(entry);
//	if (entry != NULL) {
//		current->left = Create_Tree();
//		current->right = Create_Tree();
//	}
//	return current;
//}
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
//

int main() {
	Binary_Tree<char> bTree;
	bTree.create_by_preorder_and_inorder();
	cout << "width:\n";
	cout << bTree.cal_width() << endl;
	cout << "度数为2的节点个数:\n";
	cout << bTree.cal_two_degree_nodes(bTree.root, 0) << endl;
	cout << "bTree.root.left 的深度:\n";
	cout << bTree.find_degree(bTree.root) << endl;
	if (bTree.is_binary_search_tree()) cout << "是二分查找树\n";
	else cout << "不是二分查找树\n";


	return 0;
}