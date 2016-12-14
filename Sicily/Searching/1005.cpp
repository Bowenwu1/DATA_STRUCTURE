// AVL TREE
#include <iostream>
using namespace std;
enum BF {leftHiger, equalHigh, rightHiger};
class AVLTree {
    private:
    struct Node {
        int ele;
        BF balanceFactor;
        Node* left;
        Node* right;
        Node(int e, Node* l = NULL, Node* r = NULL):
        ele(e), left(l), right(r) {
            balanceFactor = equalHigh;
        }
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };
        Node* root;
        void preOrderRecursive(Node* r) {
            if (r) {
                cout << r->ele << " ";
                preOrderRecursive(r->left);
                preOrderRecursive(r->right);
            }
        }
        void avlInsert(Node* & root, int ele, bool & taller) {
            if (root == NULL) {
                root = new Node(ele);
                taller = true;
                return;
            }
            if (ele == root->ele) {
                taller = false;
                return;
            }
            // smaller, left tree
            if (ele < root->ele) {
                avlInsert(root->left, ele, taller);
                if (taller == true) {
                    switch(root->balanceFactor) {
                        case leftHiger:
                            leftBalance(root);
                            taller = false;
                            break;
                        case equalHigh:
                            root->balanceFactor = leftHiger;
                            break;
                        case rightHiger:
                            root->balanceFactor = equalHigh;
                            taller = false;
                            break;
                    }
                }
                return;
            }
            avlInsert(root->right, ele, taller);
            if (taller == true) {
                switch(root->balanceFactor) {
                    case leftHiger:
                        root->balanceFactor = equalHigh;
                        taller = false;
                        break;
                    case equalHigh:
                        root->balanceFactor = rightHiger;
                        break;
                    case rightHiger:
                        rightBalance(root);
                        taller = false;
                        break;
                }
            }
        }
        void leftBalance(Node* & root) {
            if (root->left->balanceFactor == leftHiger) {
                rotate_right(root);
                // !!!
                root->balanceFactor = equalHigh;
                root->right->balanceFactor = equalHigh;
            } else if (root->left->balanceFactor == rightHiger) {
                Node* subTree = root->left->right;
                switch(subTree->balanceFactor) {
                    case equalHigh:
                        root->balanceFactor = equalHigh;
                        root->left->balanceFactor = equalHigh;
                        break;
                    case rightHiger:
                        root->balanceFactor = equalHigh;
                        root->left->balanceFactor = leftHiger;
                        break;
                    case leftHiger:
                        root->balanceFactor = rightHiger;
                        root->left->balanceFactor = equalHigh;
                        break;
                }
                subTree->balanceFactor = equalHigh;
                rotate_left(root->left);
                rotate_right(root);
            }
        }
        void rightBalance(Node* & root) {
            if (root->right->balanceFactor == rightHiger) {
                rotate_left(root);
                // !!!
                root->balanceFactor = equalHigh;
                root->left->balanceFactor = equalHigh;
            } else if (root->right->balanceFactor == leftHiger) {
                Node* subTree = root->right->left;
                switch(subTree->balanceFactor) {
                    case equalHigh:
                        root->balanceFactor = equalHigh;
                        root->right->balanceFactor = equalHigh;
                        break;
                    case leftHiger:
                        root->balanceFactor = equalHigh;
                        root->right->balanceFactor = rightHiger;
                        break;
                    case rightHiger:
                        root->balanceFactor = leftHiger;
                        root->right->balanceFactor = equalHigh;
                        break;
                }
                subTree->balanceFactor = equalHigh;
                rotate_right(root->right);
                rotate_left(root);
            }
        }
        void rotate_left(Node* & root) {
            Node* right = root->right;
            root->right = right->left;
            right->left = root;
            root = right;
        }
        void rotate_right(Node* & root) {
            Node* left = root->left;
            root->left = left->right;
            left->right = root;
            root = left;
        }
    public:
        AVLTree() {
            root = NULL;
        }
        ~AVLTree() {
            if (root) delete root;
        }
        void insert(int ele) {
            bool taller;
            avlInsert(root, ele, taller);
        }
        void preOrderTravel() {
            preOrderRecursive(this->root);
        }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        AVLTree test;
        int n, temp;
        cin >> n;
        while (n--) {
            cin >> temp;
            test.insert(temp);
        }
        test.preOrderTravel();
        cout << endl;
    }
}