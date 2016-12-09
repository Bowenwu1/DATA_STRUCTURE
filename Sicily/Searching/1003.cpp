#include <iostream>
#include <stdio.h>
#include <memory.h>
using std::cout;
using std::endl;
template<typename T>
void swap(T & a, T & b) {
    T c = a;
    a = b;
    b = c;
}
const int MAX = 200000020;
const int MOVE = 10000000;
// this bug cost me long time to debug
// I didn't consider that the number will be negative
// !!!!!!!!!!!!!!!!!!!!
bool whetherExisted[MAX];

void insertToHeap(int* heap, int & currentSize, int elem, int maxSize) {
    // cout << "insert " << elem << " heap[0] is " << heap[0] << endl;
    if (currentSize) {
        if (currentSize < maxSize) {
            heap[currentSize++] = elem;
            int father = (currentSize - 2) / 2;
            int son = currentSize - 1;
            while (son != 0 && father >= 0) {
                if (heap[father] <= heap[son])
                    break;
                swap(heap[father], heap[son]);
                son = father;
                father = (father - 1) / 2;
            }
        } else {
            if (heap[0] < elem) {
                // delete heap[0]
                heap[0] = heap[currentSize - 1];
                currentSize--;
                int father = 0;
                int son = 2 * father + 1;
                while (son < currentSize) {
                    if (son + 1 < currentSize && heap[son + 1] < heap[son])
                        ++son;
                    if (heap[son] >= heap[father])
                        break;
                    swap(heap[son], heap[father]);
                    father = son;
                    son = 2 * son + 1;                    
                }
                // cout << "finish delete element!" << endl;
                // insert elem
                heap[currentSize++] = elem;
                father = (currentSize - 2) / 2;
                son = currentSize - 1;
                while (son != 0 && father >= 0) {
                    if (heap[father] <= heap[son])
                        break;
                    swap(heap[father], heap[son]);
                    son = father;
                    father = (father - 1) / 2;
                }
                // cout << "finsh add element!" << endl;
            }
        }
    } else {
        heap[0] = elem;
        currentSize++;
    }
}
int main() {
    memset(whetherExisted, 0, sizeof(bool) * MAX);
    int heapSize = 0;
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int* heap = new int[k];
    int temp;
    // mantain a maximum heap
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        if (whetherExisted[temp + MOVE]) continue;
        // insertToHeap
        whetherExisted[temp + MOVE] = true;
        insertToHeap(heap, heapSize, temp, k);
    }
    if (n)
        printf("%d\n", heap[0]);
    else
        printf("\n");
    delete[] heap;
}
