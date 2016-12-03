#include <iostream>
#include <stack>

template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

using namespace std;

template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)) {
	if (root) {
		inorder_recursive(root->left, visit);
		visit(root->elem);
		inorder_recursive(root->right, visit);
	}
}

template <typename T>
struct myNode
{
	BinaryNode<T>* elem;
	/* whetherVisit mean whether their LeftNode has been pushed into stack */
	bool whetherVisit = false;
	myNode(BinaryNode<T>* e, bool w = false):elem(e), whetherVisit(w) {}
};
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)) {
	if (root == NULL)
		return;
	stack<myNode<T> > data;
	data.push(myNode<T>(root));
	while (!data.empty()) {
		if (data.top().whetherVisit) {
			myNode<T> temp = data.top();
			data.pop();
			visit(temp.elem->elem);
			if (temp.elem->right) {
				data.push(myNode<T>(temp.elem->right));
			}
		} else {
			if (data.top().elem->left) {
				data.front().whetherVisit = true;
				data.push(myNode<T>(data.front().elem->left));
			}
		}
	}
}
template<typename T>
void visit(T &x) {
	cout << x << " " << endl;
}
int main() {
	BinaryNode<int>* root = new BinaryNode<int>(1);
	root->left = new BinaryNode<int>(2);
	root->right = new BinaryNode<int>(3);
	root->left->left = new BinaryNode<int>(4);
	root->right->left = new BinaryNode<int>(5);
	cout << "inorder_recursive : " << endl;
	inorder_recursive(root, visit);
	cout << "inorder : " << endl;
	inorder(root, visit);
}
