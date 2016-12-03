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
	bool whetherVisit;
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
			data.top().whetherVisit = true;
			if (data.top().elem->left) {
				data.push(myNode<T>(data.top().elem->left));
			}
		}
	}
}
#include <queue>
template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
	if (root == NULL)
		return;
	queue<BinaryNode<T>*> data;
	data.push(root);
	while (!data.empty()) {
		visit(data.front()->elem);
		if (data.front()->left) {
			data.push(data.front()->left);
		}
		if (data.front()->right) {
			data.push(data.front()->right);
		}
		data.pop();
	}
}
template<typename T>
void insert(BinaryNode<T>*& root, T ele) {
	if (root) {
		if (ele < root->elem) {
			insert(root->left, ele);
		} else {
			insert(root->right, ele);
		}
	} else {
		root = new BinaryNode<T>(ele);
	}
}
template<typename T>
void clearTree(BinaryNode<T>*& root) {
	if (root) {
		clearTree(root->left);
		clearTree(root->right);
		delete root;
		root = NULL;
	}
}
/* test function */
template<typename T>
void visit(T &x) {
	cout << x << " ";
}
int main() {
	// BinaryNode<int>* root = new BinaryNode<int>(1);
	// root->left = new BinaryNode<int>(2);
	// root->right = new BinaryNode<int>(3);
	// root->left->left = new BinaryNode<int>(4);
	// root->right->left = new BinaryNode<int>(5);
	// cout << "inorder_recursive : " << endl;
	// inorder_recursive(root, visit);
	// cout << "inorder : " << endl;
	// inorder(root, visit);
	// cout << "levelTraversal : " << endl;
	// levelTraversal(root, visit);
	while (1) {
	BinaryNode<int>* root = NULL;
		int T;
		cin >> T;
		if (!T)
			break;
		int n;
		cin >> n;
		while(n--) {
			int temp;
			cin >> temp;
			insert(root, temp);
		}
		inorder(root, visit);
	}
}
