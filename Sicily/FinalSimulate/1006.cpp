#include <iostream>
#include <vector>
using namespace std;

class hashTable {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int e = -1, Node* n = NULL):data(e), next(n) {}
            ~Node() {
                if (next) delete next;
            }
        };
        vector<Node> data;
        int hash(int key) { return key % 11; }
    public:
        hashTable() {
        	data.resize(11);
        	// cout << "data size : " << data.size() << endl;
        }
        void insert(int ele) {
            int key = hash(ele);
            if (data[key].next) {
                Node* temp = data[key].next;
                data[key].next = new Node(ele, temp);
            } else {
                data[key].next = new Node(ele);
            }
        }
        int find(int ele) {
            int key = hash(ele);
            if (data[key].next) {
                Node* temp = data[key].next;
                int ret = 0;
                while (temp) {
                    if (temp->data == ele) return ret;
                    temp = temp->next;
                    ++ret;
                }
            }
            return -1;
        }
};

int main() {
    int N;
    cin >> N;
    hashTable test;
    while (N--) {
        char op;
        int ele;
        cin >> op >> ele;
        if (op == 'F') {
            cout << test.find(ele) << endl;
        } else {
            test.insert(ele);
        }
    }
}
