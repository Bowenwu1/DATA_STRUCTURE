#include <queue>
#include <iostream>
#include <vector>
#include <functional>
#include <memory.h>
using namespace std;
const int MAX = 200000020;
const int MOVE = 10000000;
bool whetherExisted[MAX];
int main() {
    memset(whetherExisted, false, sizeof(bool)*MAX);
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int> > data;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (whetherExisted[temp + MOVE]) continue;
        whetherExisted[temp + MOVE] = true;
        if (data.size() < k) {
            data.push(temp);
        } else {
            int first = (data.top());
            if (temp > first) {
                data.pop();
                data.push(temp);
            }
        }
    }
    cout << (data.top()) << endl;
}