#include <iostream>
using namespace std;

void mycin(int & i, int & j) {
    cin >> i >> j;
    --i, --j;
}

void init(int** & graph, bool* & visited, int size) {
    graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            graph[i][j] = -1;
    visited = new bool[size];
    for (int i = 0; i < size; ++i)
        visited[i] = false;
}
bool whetherHaveChildrenToVisit(int** graph, int index, int size) {
    for (int i = 0; i < size; ++i) {
        if (graph[index][i] == 0)
            return true;
    }
    return false;
}
void DFS(int** graph, bool* visited, int start, int end, int size, int enter) {
    // cout << "visit " << "(" << start << "," << end << ")" << endl;
    if (!visited[end]) {
        // tree edge
        graph[start][end] = 1;
        visited[end] = true;
    } else {
        if (whetherHaveChildrenToVisit(graph, end, size)) {
            graph[start][end] = 2;
        } else {
            if (start == enter)
                graph[start][end] = 3;
            else
                graph[start][end] = 4;
        }
    }
    // for (int i = end + 1; i < size; ++i) {
    //     if (graph[start][i] == 0)
    //         DFS(graph, visited, start, i, size);
    // }
    for (int i = 0; i < size; ++i) {
        if (graph[end][i] == 0)
            DFS(graph, visited, end, i, size, enter);
    }
}
void print(int** graph, int i, int j) {
   cout << "edge (" << i + 1 << "," << j + 1 << ") is ";
    switch(graph[i][j]) {
        case 1:
            cout << "Tree Edge";
            break;
        case 2:
            cout << "Back Edge";
            break;
        case 3:
            cout << "Down Edge";
            break;
        case 4:
            cout << "Cross Edge";
            break;
        default:
            break;
    }
    cout << endl;
}
int main() {
    int** graph;
    bool* visited;
    int n, m;
    cin >> n >> m;
    // allocate memory
    init(graph, visited, n);
    int x, y;
    for (int i = 0; i < m; ++i) {
        mycin(x, y);
        /* 0 indicate there is a edge and no visit
         * 1 indicate Tree Edge
         * 2 indicate Back Edge
         * 3 indicate Down Edge
         * 4 indicate Cross Edge
         */
        graph[x][y] = 0;
    }
    visited[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 0)
                DFS(graph, visited, i, j, n, i);
        }
    }
    // print result
    int test;
    cin >> test;
    while (test--) {
        mycin(x, y);
        print(graph, x, y);
    }
}
