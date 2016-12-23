#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> data(n);
        while (n--) cin >> data[n];
        sort(data.begin(), data.end());
        for (auto iter = data.begin(); iter != data.end(); ++iter)
            cout << *iter << endl;
    }
}