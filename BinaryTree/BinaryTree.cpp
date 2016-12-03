#include "BinaryTree.hpp"

BinaryTree::BinaryTree(const std::vector<elementType> & data) {
	for (int i = 0; i < data.size(); ++i)
		this->defaultInsert(data[i]);
}

void BinaryTree::defaultInsert(elementType data) {
	if (top == NULL) {
		top = new Node(data);
		top->layer = 1;
	} else {
		Node* temp = top;
		while (1) {
			if (data < temp->e) {
				if (temp->left == NULL) {
					temp->left = new Node(data);
					temp->left->layer = temp->layer + 1;
					break;
				} else {
					temp = temp->left;
				}
			} else {
				if (temp->right == NULL) {
					temp->right = new Node(data);
					temp->right->layer = temp->layer + 1;
					break;
				} else {
					temp = temp->right;
				}
			}
		}
	}
}

void BinaryTree::insert(elementType data, std::string pos, elementType father) {
	Node* pre = this->find(top, father);
	if (pre == nullptr)
		return;

	int layer = pre->layer + 1;
	Node* insertNode = nullptr;
	if (pos == "left") {
		insertNode = pre->left;
		if (insertNode == nullptr) {
			pre->left = new Node(data);
		}
		else {
			Node* temp = insertNode;
			pre->left = new Node(data);
			pre->left->left = temp;
			pre->left->left->layer = layer + 1;
		}
		pre->left->layer = layer;
	}
	else if (pos == "right") {
		insertNode = pre->right;

		if (insertNode == nullptr) {
			pre->right = new Node(data);
		}
		else {
			Node* temp = insertNode;
			pre->right = new Node(data);
			pre->right->right = temp;
			pre->right->right->layer = layer + 1;
		}
		pre->right->layer = layer;
	}
	else {
		return;
	}

}

void BinaryTree::roll(Node* start) {
	if (start) {
		Node* temp = start->left;
		start->left = start->right;
		start->right = temp;
		this->roll(start->left);
		this->roll(start->right);
	}
}
/* this is what Teacher Gao asked */
void BinaryTree::verticalPrint(Node* start, int layer = 0) {
	if (start) {
		this->verticalPrint(start->right, layer + 2);
		for (int i = 0; i < layer; ++i)
			std::cout << ' ';
		std::cout << start->e << std::endl;
		this->verticalPrint(start->left, layer + 2);
	} else {
		for (int i = 0; i < layer; ++i)
			std::cout << ' ';
		std::cout << " " << std::endl;
	}
}

/* I didn't finish this function well*/
void BinaryTree::horizentalPrint(Node* start) {
	std::vector<Node*> data;
	std::vector<Node*>::iterator iter;
	int startLayer = start->layer;
	data.push_back(start);
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] != NULL) {
			data.push_back(data[i]->left);
			data.push_back(data[i]->right);
		}
	}
	int maxLayer = 0;
	for (int i = data.size() - 1; i > -1; --i) {
		if (data[i] != NULL) {
			maxLayer = data[i]->layer;
			break;
		}
	}
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] != NULL) {
			std::cout << data[i]->e << " " << std::endl;
		}
		else {
			std::cout << "NULL " << std::endl;
		}
	}
	int spaceNum = maxLayer - startLayer;
	int printIndex = 0;
	for (int i = 0; i < maxLayer - startLayer; i++) {
		for (int j = 0; j < 2 * spaceNum; j++)
			std::cout << ' ';
		spaceNum--;
		for (int j = 0; j < (i ? 2 * i : 1); j++) {
			if (data[printIndex] != NULL) {
				std::cout << data[printIndex]->e << " ";
			} else {
				std::cout << "  ";
			}
			printIndex++;
		}
		std::cout << std::endl;
	}
}
BinaryTree::Node* BinaryTree::find(Node* start, elementType e){
	if (start) {
		if (e == start->e)
			return start;
		Node* left = this->find(start->left, e);
		if (left != nullptr)
			return left;
		Node* right = this->find(start->right, e);
		if (right != nullptr)
			return right;
	}
	return nullptr;
}
BinaryTree::Node* BinaryTree::getTopNode() {
	return top;
}


