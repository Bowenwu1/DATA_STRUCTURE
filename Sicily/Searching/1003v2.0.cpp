// Problem#: 19589
// Submission#: 4963577
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 19589
// Submission#: 4958716
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// 0.61s
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
const int MAX =  20000020;
const int MOVE = 10000000;
bool whetherExisted[MAX];

char str[91000000],*p=str;
inline int getint(){
    int re=0, m=1;
    for(;!isdigit(*p);p++)if((*p)=='-')m=-1;
    while(isdigit(*p))re=re*10+*p++-48;
    return m*re;
}
int main() {
    // memset(whetherExisted, 0, sizeof(bool) * MAX);
    fread(p,1,91000000,stdin);
    int n;
    n = getint();
    int k;
    k = getint();
    // int* heap = new int[k];
    int temp;
    // mantain a maximum heap
    for (int i = 0; i < n; ++i) {
        temp = getint();
        whetherExisted[temp + MOVE] = true;
        // insertToHeap(heap, heapSize, temp, k);
    }
    // if (n)
    //     printf("%d\n", heap[0]);
    // else
    //     printf("\n");
    // delete[] heap;
    int result = 0;
    --k;
    for (int i = MAX - 1; i > -1; --i) {
        if (!whetherExisted[i]) continue;
        if (result == k) {
            printf("%d\n", i - MOVE);
            break;
        }
        if (whetherExisted[i])
            result++;
    }
}