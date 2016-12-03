#include <iostream>
#include <queue>

using namespace std;
//#define DEBUG
int maxHeight = 0;
int maxWidth = 0;

void mycin(int & i, int & j) {
    cin >> i >> j;
    --i, --j;
}

void init(int** & graph, bool* & visited, int* & floor, int size) {
    graph = new int*[size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            graph[i][j] = -1;
    visited = new bool[size];
    for (int i = 0; i < size; ++i)
        visited[i] = false;
    floor = new int[size];
    for (int i = 0; i < size; ++i)
        floor[i] = 0;
}
void deleteGraph(int** & graph, bool* & visited, int* & floor, int size) {
    delete[] visited;
    visited = NULL;
    for (int i = 0; i < size; ++i)
        delete[] graph[i];
    delete[] graph;
    delete[] floor;
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
bool isRoot(int** graph, int index, int size) {
    for (int i = 0; i < size; ++i) {
        if (graph[i][index] != -1)
            return false;
    }
    return true;
}
void BFS(int** graph, int* floor, int size) {
    queue<int> data;
    bool* visited = new bool[size];
    for (int i = 0; i < size; ++i)
        visited[i] = false;
    for (int i = 0; i < size; i++) {
        if (!visited[i] && isRoot(graph, i, size)) {
            #ifdef DEBUG
            cout << "travel tree of root : " << i << endl;
            #endif
            data.push(i);
            visited[i] = true;
            while (!data.empty()) {
                int presentIndex = data.front();
                data.pop();
                #ifdef DEBUG
                cout << "Now in " << presentIndex << endl;
                #endif
                for (int i = 0; i < size; ++i) {
                    if (!visited[i] && graph[presentIndex][i] != -1) {
                        #ifdef DEBUG
                        cout << "Path : (" << presentIndex << " ," << i << ")" << endl;
                        #endif
                        floor[i] = floor[presentIndex] + 1;
                        if (floor[i] > maxHeight)
                            maxHeight = floor[i];
                        data.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    // calculate width
    for (int i = 0; i <= maxHeight; ++i) {
        int width = 0;
        for (int j = 0; j < size; ++j) {
            if (floor[j] == i)
                ++width;
        }
        maxWidth = width > maxWidth ? width : maxWidth;
    }
    delete[] visited;
}

// bool isTree(int** graph, int size) {
//     for (int i = 0; i < size; ++i)
//         for (int j = 0; j < size; ++j) {
//             if (graph[i][j] > 1)
//                 return false;
//         }
//     return true;
// }
bool checkCycle(int** graph, bool* visited, int str, int size) {
    if (visited[str])
        return true;
    visited[str] = true;
    for (int i = 0; i < size; ++i) {
        if (graph[str][i] == 0)
            if (checkCycle(graph, visited, i, size))
                return true;
    }
    visited[str] = false;
    return false;
}
bool isTree(int** graph, int size) {
    // check two edges pointing to the same node
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (graph[j][i] != -1)
                count++;
        }
        if (count > 1)
            return false;
    }
    // check whetherThereis Loop
    bool* visited = new bool[size];
    for (int i = 0; i < size; ++i)
        visited[i] = false;
    for (int i = 0; i < size; ++i) {
            if (checkCycle(graph, visited, i, size))
                return false;
    }
    delete[] visited;
    return true;
}

int main() {
    while (1) {
        int** graph;
        bool* visited;
        int* floor;
        int n, m;
        cin >> n >> m;
        if (n == 0)
            break;
        // allocate memory
        init(graph, visited, floor, n);
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
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (graph[i][j] == 0)
        //             DFS(graph, visited, i, j, n, i);
        //     }
        // }
        if (!isTree(graph, n))
            cout << "INVALID" << endl;
        else {
            BFS(graph, floor, n);
            cout << maxHeight << " " << maxWidth << endl;
        }
//        deleteGraph(graph, visited, floor, n);
    }
}
