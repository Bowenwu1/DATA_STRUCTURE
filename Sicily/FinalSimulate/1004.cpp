#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, m, v1, v2;
        cin >> n >> m >> v1 >> v2;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; ++i) matrix[i].resize(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                matrix[i][j] = -1;

        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            matrix[x][y] = matrix[y][x] = 1;
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    // there is a road between i j
                    if (matrix[i][j] != -1) {
                        if (matrix[i][k] != -1 && matrix[k][j] != -1
                            && matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                                matrix[i][j] = matrix[j][i] = matrix[i][k] + matrix[k][j];
                            }
                    } else {
                        if (matrix[i][k] != -1 && matrix[k][j] != -1)
                            matrix[i][j] = matrix[j][i] = matrix[i][k] + matrix[k][j];
                    }
                }
        cout << matrix[v1][v2] << endl;
    }
}
