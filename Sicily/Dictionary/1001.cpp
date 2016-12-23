#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    while (1) {
        cin >> n;
        if (!n) return 0;
        map<int, int> data;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            if (data.find(temp) == data.end())
                data[temp] = 1;
            else
                ++data[temp];
        }
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            if (iter->second % 2) {
                cout << iter->first << endl;
                break;
            }
        }
    }
}