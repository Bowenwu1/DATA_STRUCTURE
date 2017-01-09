#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void visit(int startIndex, bool** data, vector<bool> & visited, int size) {
    // int size = visited.size();
    visited[startIndex] = true;
//    cout << "visit " << startIndex << endl;
    for (int i = 0; i < size; ++i) {
        if (data[startIndex][i] && !visited[i]) {
//        	cout << "from " << startIndex << " to " << i << endl;
            visit(i, data, visited, size);
        }
    }
}

void BFSvisit(bool** data, int size) {
	vector<int> result;
	vector<bool> visited;
	result.resize(size, -1);
	visited.resize(size, false);
	queue<int> q;
	q.push(0);
    result[0] = 0;
	visited[0] = true;
    while (!q.empty()) {
        int frontIndex = q.front();
        q.pop();
        for (int i = 0; i < size; ++i) {
            if (data[i][frontIndex] && !visited[i]) {
                visited[i] = true;
                result[i] = result[frontIndex] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < size; ++i)
        cout << result[i] << " ";
    cout << endl;
}
int main() {
    int n, m;
    cin >> n >> m;
    bool** data;
    data = new bool*[n];
    for (int i = 0; i < n; i++)
        data[i] = new bool[n];
    // input data
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    		data[i][j] = false;
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        data[x][y] = true;
        data[y][x] = true;
    }
    vector<bool> visited;
    visited.resize(n, false);
    int result = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (!visited[i]) {
    //    	cout << "go into " << i << endl;
    //         result++;
    //         visit(i, data, visited, n);
    //     }
    // }
    // cout << result << endl;
    BFSvisit(data, n);
}
