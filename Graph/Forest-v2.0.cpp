#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXSIZE 1000
//#define DEBUG
// the index of graph start from 1
// int graph[MAXSIZE][MAXSIZE];
// int width[MAXSIZE];
// int f[MAXSIZE];
// int inGrade[MAXSIZE];
// bool visited[MAXSIZE];
int** graph;
int* width;
int* f;
int* inGrade;
bool* visited;

void init() {
    for (int i = 0; i < MAXSIZE; ++i) {
        width[i] = f[i] = inGrade[i] = 0;
        visited[i] = false;
        for (int j = 0; j < MAXSIZE; ++j)
            graph[i][j] = 0;
    }
}
void initVisited() {
    for (int i = 0; i < MAXSIZE; ++i)
        visited[i] = false;
}
void allocateMemory() {
    graph = new int*[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i)
        graph[i] = new int[MAXSIZE];
    width = new int[MAXSIZE];
    f = new int[MAXSIZE];
    inGrade = new int[MAXSIZE];
    visited = new bool[MAXSIZE];
}
// DFS
bool whetherContainLoop(int index, int n) {
    #ifdef DEBUG
    cout << "visit : " << index << endl;
    #endif
    if (visited[index])
        return true;
    visited[index] = true;
    for (int i = 1; i <= n; ++i) {
        if (/* there is a edge */ graph[index][i]) {
            #ifdef DEBUG
            cout << "from :" << index << " to " << i << endl;
            #endif
                if (whetherContainLoop(i, n))
                    return true;
        }
    }
    return false;
}

int main() {
    allocateMemory();
    while (1) {
        init();
        int n, m;
        bool valid = true;
        cin >> n >> m;
        if (!n) break;
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            graph[x][y] = 1;
            ++inGrade[y];
            if (inGrade[y] > 1) {
                valid = false;
            }
        }
        // end condition one
        if (!valid) {
            #ifdef DEBUG
            cout << "condition one " << endl;
            #endif
            cout << "INVALID" << endl;
            continue;
        }
        // check whether contain loop
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                initVisited();
                if (whetherContainLoop(i, n)) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) {
            #ifdef DEBUG
            cout << "condition two" << endl;
            #endif
            cout << "INVALID" << endl;
            continue;
        }

        // calculate
        queue<int> data;
        // BFS start from every root
        for (int i = 1; i <= n; ++i) {
            if (!inGrade[i]) {
                data.push(i);
                f[i] = 0;
                ++width[f[i]];
                while (!data.empty()) {
                    int presentIndex = data.front();
                    data.pop();
                    for (int j = 1; j <= n; ++j) {
                        if (graph[presentIndex][j]) {
                            f[j] = f[presentIndex] + 1;
                            width[f[j]]++;
                            data.push(j);
                        }
                    }
                }
            }
        }
        sort(f, f + MAXSIZE);
        sort(width, width + MAXSIZE);
        cout << f[MAXSIZE - 1] << " " << width[MAXSIZE - 1] << endl;
    }
}
