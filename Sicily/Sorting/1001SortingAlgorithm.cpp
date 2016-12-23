#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) return 0;
        vector<int> data(n);
        for (int i = 0; i < n; ++i) cin >> data[i];
        sort(data.begin(), data.end());
        cout << data[0];
        for (int i = m; i < n; i += m) {
            cout << " " << data[i];
        }
        cout << endl;
    }
}