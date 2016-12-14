// AVL TREE
#include <iostream>
using namespace std;
enum BF {leftHiger, equal, rightHiger};
class AVLTree {
    private:
        struct Node {
            int ele;
            BF balanceFactor;
            Node* left, right;
            Node(int e, Node* l = NULL, Node* r = NULL):
            ele(e), left(l), right(r) {}
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
    public:
        AVLTree() {
            root = NULL;
        }
        ~AVLTree() {
            if (root) delete root;
        }
        void insert(int ele) {

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