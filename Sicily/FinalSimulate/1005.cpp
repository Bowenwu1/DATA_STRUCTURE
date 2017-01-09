#include <iostream>
#include <vector>
using namespace std;

int M;
int myhash(int key) {
    return key % M;
}

void insert(int ele, vector<int> & data) {
    int index = myhash(ele);
    while (data[index] != -1) {
        index = (index + 1) % M;
    }
    data[index] = ele;
}
void print(const vector<int> & data) {
    for (int i = 0; i < M; ++i) {
        // cout << i << "#";
        // if (data[i] == -1 || data[i] % M != i) {
        //     cout << "NULL" << endl;
        //     continue;
        // } else {
        //     int index = i;
        //     cout << data[index];
        //     index = (index + 1) % M;
        //     while (index != i) {
        //         if (data[index] == -1) break;
        //         if (data[index] % M == i) {
        //             cout << " " << data[index];
        //         }
        //         index = (index + 1) % M;
        //     }
        //     cout << endl;
        // }
        cout << i << "#";
        if (data[i] == -1) {
            cout << "NULL" << endl;
        } else {
            cout << data[i] << endl;
        }
    }
}
int main() {
    int n;
    cin >> n >> M;
    vector<int> data(M, -1);
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        insert(temp, data);
    }
    print(data);
}
