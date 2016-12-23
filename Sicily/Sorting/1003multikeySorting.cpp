#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int C, N;
    while (cin >> C >> N) {
        vector<int> operation(N);
        for (int i = 0; i < N; ++i) cin >> operation[i];
        vector<int> result(N);
        vector<bool> whetherExist(C + 1, false);
        int resultIndex = 0;
        for (int i = N - 1; i > -1; --i) {
            if (!whetherExist[operation[i]]) {
                result[resultIndex++] = operation[i];
                whetherExist[operation[i]] = true;
            }
        }
        cout << resultIndex << endl;
        cout << result[resultIndex - 1];
        for (int i = resultIndex - 2; i > -1; --i)
            cout << " " << result[i];
        cout << endl;
    }
}