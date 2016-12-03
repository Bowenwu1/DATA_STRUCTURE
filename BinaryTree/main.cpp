#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::cout << "二叉树测试程序： " << std::endl;
	std::cout << "请输入根结点 ： " << std::endl;
	int root;
	cin >> root;
	std::vector<int> ttt;
	ttt.push_back(root);
	BinaryTree testTree(ttt);
	std::cout << "I --插入元素" << std::endl
		<< "Q --结束输入" << std::endl
		<< "P --打印该数" << std::endl;
	while (1) {
		std::string op;
		std::cin >> op;
		if (op == "I") {
			std::cout << "请输入 要插入的元素 插入右子树或者左子树 父节点的值" << std::endl;
			std::string pos;
			int father;
			int data;
			cin >> data >> pos >> father;
			testTree.insert(data, pos, father);
		}
		else if (op == "Q") {
			break;
		}
		else if (op == "P") {
			testTree.verticalPrint(testTree.getTopNode(), 0);
		}
		else {
			std::cout << "非法的输入，请重试 " << std::endl;
		}
	}
	std::cout << "翻转前：" << std::endl;
	testTree.verticalPrint(testTree.getTopNode(), 0);
	testTree.roll(testTree.getTopNode());
	std::cout << "翻转后: " << std::endl; 
	testTree.verticalPrint(testTree.getTopNode(), 0);
	/*std::cout << "垂直打印 ：" << std::endl;
	testTree.horizentalPrint(testTree.getTopNode());*/
	return 0;
}
