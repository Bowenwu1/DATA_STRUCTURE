#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::cout << "���������Գ��� " << std::endl;
	std::cout << "���������� �� " << std::endl;
	int root;
	cin >> root;
	std::vector<int> ttt;
	ttt.push_back(root);
	BinaryTree testTree(ttt);
	std::cout << "I --����Ԫ��" << std::endl
		<< "Q --��������" << std::endl
		<< "P --��ӡ����" << std::endl;
	while (1) {
		std::string op;
		std::cin >> op;
		if (op == "I") {
			std::cout << "������ Ҫ�����Ԫ�� �������������������� ���ڵ��ֵ" << std::endl;
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
			std::cout << "�Ƿ������룬������ " << std::endl;
		}
	}
	std::cout << "��תǰ��" << std::endl;
	testTree.verticalPrint(testTree.getTopNode(), 0);
	testTree.roll(testTree.getTopNode());
	std::cout << "��ת��: " << std::endl; 
	testTree.verticalPrint(testTree.getTopNode(), 0);
	/*std::cout << "��ֱ��ӡ ��" << std::endl;
	testTree.horizentalPrint(testTree.getTopNode());*/
	return 0;
}
