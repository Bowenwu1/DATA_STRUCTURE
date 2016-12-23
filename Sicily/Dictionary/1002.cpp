#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    bool whetherFirst = false;
    while ((scanf("%d", &n)) != EOF) {
        if (whetherFirst)
            cout << endl;
        whetherFirst = true;
        map<int, int> data;
        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            if (data.find(temp) == data.end())
                data[temp] = 1;
            else
                ++data[temp];
        }
        if (data.size()) {
            for (auto iter = data.begin(); iter != data.end(); ++iter) {
                cout << iter->first << " " << iter->second << endl;
            }
        }
    }
}