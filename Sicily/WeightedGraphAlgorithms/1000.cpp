#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
#define MAX_SIZE 100001
vector<int> data;

int getFather(int x) {
    if (x == data[x]) return x;
    data[x] = getFather(data[x]);
    return data[x];
}
int main() {
    data.resize(MAX_SIZE, 0);
    for (int i = 0; i < data.size(); ++i)
        data[i] = i;
    int x, y;
    while ((scanf("%d %d", &x, &y)) != EOF) {
        int xfather = getFather(x);
        int yfather = getFather(y);
        if (xfather != yfather) {
            cout << x << " " << y << endl;
            data[xfather] = yfather;
        }
    }
}