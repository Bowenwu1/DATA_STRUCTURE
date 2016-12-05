#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 501
using namespace std;
struct edge {
    int u, v, weight;
};
vector<edge> e;
vector<int> data;
void init() {
    data.resize(MAX_SIZE, 0);
    for (int i = 0; i < data.size(); ++i)
        data[i] = i;
    e.resize(124760);
}

int getFather(int x) {
    if (x == data[x]) return x;
    data[x] = getFather(data[x]);
    return data[x];
}

bool whetherConnect(int x, int y) {
    int xfather = getFather(x);
    int yfather = getFather(y);
    if (xfather != yfather) {
        data[xfather] = yfather;
        // cout << x << " " << y << endl;
        return true;
    }
    return false;
}

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int findMinPathInSpanningTree(int size) {
    int maxWeight = 0;
    for (int i = 0; i < size; ++i) {
        if (whetherConnect(e[i].u, e[i].v))
            maxWeight = e[i].weight > maxWeight ? e[i].weight : maxWeight;
    }
    return maxWeight;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        int n;
        int temp;
        cin >> n;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> temp;
                if (j > i) {
                    e[count].u = i;
                    e[count].v = j;
                    e[count].weight = temp;
                    count++;
                }
            }
        }
        sort(e.begin(), e.begin() + count, cmp);
        // cout << "u  v  count" << endl;
        // for (int i = 0; i < count; ++i) {
        //     cout << e[i].u << " " << e[i].v << " " << e[i].weight << endl;
        // }
        cout << findMinPathInSpanningTree(count) << endl;
        if (T != 0)
            cout << endl;
    }
}

