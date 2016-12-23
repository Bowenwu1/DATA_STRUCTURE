#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(const vector<int> & s, int x) {
    bool small = true;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == x) {
            small = false;
            continue;
        }
        if (small && s[i] > x) return false;
        else if (!small && s[i] < x) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> data(n);
        int result = 0;
        for (int i = 0; i < n; ++i) cin >> data[i];
        for (int i = 0; i < n; ++i) {
            if (binarySearch(data, data[i])) ++result;
        }
        cout << result << endl;
    }
}