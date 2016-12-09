#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct Node {
    int elem;
    Node* next;
    Node() {
        elem = 0;
        next = NULL;
    }
    Node(const Node & other) {
        elem = other.elem;
        next = other.next;
    }
    Node(int e, Node* n = NULL):elem(e), next(n) {}
    ~Node() {
        if (next)
            delete next;
    }
};
int hashKey(int elem) {
    return elem % 13;
}

void insert(Node* n, int ele) {
    while (n->next) n = n->next;
    n->next = new Node(ele);
}

int main() {
    int n;
    int temp;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        vector<Node> data;
        data.resize(13);
        while (n--) {
            scanf("%d", &temp);
            insert(&data[hashKey(temp)], temp);
        }
        for (int i = 0; i < 13; ++i) {
            if (data[i].next) {
                printf("%d#%d", i, data[i].next->elem);
                Node* temp = data[i].next;
                temp = temp->next;
                while (temp) {
                    printf(" %d", temp->elem);
                    temp = temp->next;
                }
                printf("\n");
            } else {
                printf("%d#NULL\n", i);
            }
        }
    }
}