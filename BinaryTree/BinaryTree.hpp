/* Created by BowenWu in 20161021
 * BinaryTree Exercise
 */

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
/* binary search tree */
/* improve it latter */
class BinaryTree {
	public:
		typedef int elementType;
		class Node {
			public:
				elementType e;
				Node(elementType data = 0):e(data) {
					left = NULL;
					right = NULL;
				}
				Node* left;
				Node* right;
				int layer;
		};
	private:
		Node* top;
		BinaryTree::Node * find(Node * start, elementType e);
	public:
		BinaryTree(const std::vector<elementType> & data);

		void defaultInsert(elementType data);
		
		void insert(elementType data, std::string pos, elementType father);
		void roll(Node* start);
		void verticalPrint(Node* start, int layer);
		void horizentalPrint(Node* start);

		Node* getTopNode();
};

#endif
