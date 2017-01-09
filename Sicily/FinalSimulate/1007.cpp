#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int temp;
        for (int i = 0; i < n; ++i) cin >> temp;
        int result = 0;
        for (int i = 0; i < n; ++i) result += i;
        cout << result << endl;
    }
}