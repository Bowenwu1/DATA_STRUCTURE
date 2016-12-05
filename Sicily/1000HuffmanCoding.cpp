#include <iostream>
#include <deque>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define V3

using namespace std;
template<typename T>
void mySwap(T & a, T & b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
class HuffmanTree {
private:
	class Node {
	public:
		Node(char ch, int wei, Node* l = NULL, Node* r = NULL):
				c(ch), weight(wei), left(l), right(r) {
			code = "";
		}
		char c;
		int weight;
		Node* left;
		Node* right;
		string code;
	};
	Node* root;

	void clearNode(Node* root) {
		if (root) {
			clearNode(root->left);
			clearNode(root->right);
			delete root;
		}
	}
	/* My bug happened here
	 * it's really time-comsuming
	 * be careful about the usage of iterator
	 * sample code:
	 std::deque<int>::iterator it = mydeque.begin();
	 ++it;

	 it = mydeque.insert (it,10);                  // 1 10 2 3 4 5
	 // "it" now points to the newly inserted 10

	 mydeque.insert (it,2,20);                     // 1 20 20 10 2 3 4 5
	 // "it" no longer valid!

	 */
	void insertNode(deque<Node*> & v, Node* n) {
		bool flag = false;
		if (v.size() >= 2) {
			Node* temp = *(v.begin());
			if (n->weight < temp->weight) {
				v.push_front(n);
				return;
			}
			for (deque<Node*>::iterator it = v.begin(); it != v.end() && (*it) != NULL; ++it) {
				if ((*it)->weight > n->weight) {
					// careful here
					//it--
					v.insert(it, n);
					flag = true;
					break;
				}
			}
			if (!flag) {
				v.push_back(n);
				flag = true;
			}
		} else if (v.empty()) {
			v.push_front(n);
			flag = true;
		} else {
			if (n->weight >= v.front()->weight) {
				v.push_back(n);
				flag = true;
			} else {
				v.push_front(n);
				flag = true;
			}
		}
#ifdef DEBUG
		cout << flag << endl;
#endif
	}
	void printDeque(const deque<Node*>& d) {
		for (auto it = d.begin(); it != d.end(); ++it) {
			cout << (*it)->weight << " ";
		}
		cout << endl;
	}
	void generatorCode(Node* root, string code = "") {
		if (root) {
			if (root->left == NULL && root->right == NULL) {
				if (code == "")
					code += "";
				root->code = code;
				return;
			}
			else {
				generatorCode(root->left, code + "0");
				generatorCode(root->right, code + "1");
			}
		}
	}
public:
	HuffmanTree(const vector<char> & data) {
		this->buildTree(data);
	}
	~HuffmanTree() {
		this->clear();
	}
	void clear() {
		this->clearNode(root);
	}
	void buildTree(const vector<char> & data) {
		/* calculate the weight
		 * with map
		 */
		map<char, int> weight;
		for (size_t i = 0; i < data.size(); ++i) {
			if (weight.find(data[i]) == weight.end()) {
				weight[data[i]] = 1;
			} else {
				++weight[data[i]];
			}
		}
		deque<Node*> nodeContainer;
		map<char, int>::iterator it = weight.begin();
		for (size_t i = 0;i < weight.size(); ++i, it++) {
			this->insertNode(nodeContainer, new Node(it->first, it->second));
		}
		while(nodeContainer.size() >= 2) {
			Node* tempSmall = nodeContainer.front();
			nodeContainer.pop_front();
			Node* tempBig = nodeContainer.front();
			nodeContainer.pop_front();
			if (tempSmall == NULL)
				cout << "tempSmall is NULL" << nodeContainer.size() << endl;
			if (tempBig == NULL)
				cout << "tempBig is NULL" << endl;
			Node* tempNew = new Node('.', tempSmall->weight + tempBig->weight
									, tempSmall, tempBig);
			this->insertNode(nodeContainer, tempNew);
#ifdef DEBUG
			this->printDeque(nodeContainer);
#endif
		}
		if (nodeContainer.size() == 1) {
			root = nodeContainer.front();
		} else {
			root = NULL;
		}
		this->generatorCode(root);
	}
	void printCode() {
		queue<Node*> data;
		vector<Node*> code;
		int result = 0;
		if (root) {
			data.push(root);
			/* level */
			while (!data.empty()) {
				Node* temp = data.front();
				if (temp->right) {
					data.push(temp->right);
				}
				if (temp->left) {
					data.push(temp->left);
				}

				if (temp->left == NULL && temp->right == NULL) {
#ifdef V1
					code.push_back(temp);
#endif
					result += temp->code.length() * temp->weight;
				}
				data.pop();
			}
		}
#ifdef V3
		cout << result << endl;
#endif
#ifdef V1
		for (int i = 0; i < code.size(); ++i) {
			for (int j = i + 1; j < code.size(); ++j) {
				if (code[i]->weight < code[j]->weight)
					mySwap(code[i], code[j]);
			}
		}
		for (int i = 0; i < code.size(); ++i)
			cout << code[i]->c << " " << code[i]->weight << " " << code[i]->code << endl;
#endif
	}
};

int main() {
	int n;
	cin >> n;
	vector<char> data;
	data.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}
	HuffmanTree tree(data);
	tree.printCode();
	return 0;
}
