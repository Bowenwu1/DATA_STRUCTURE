#include <map>
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int n;
    int temp;
    bool whetherFirst = false;
    while ((scanf("%d", &n)) != EOF) {
        if (whetherFirst)
            cout << endl;
        whetherFirst = true;
        map<int, int> data;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            if (data.find(temp) != data.end())
                data[temp]++;
            else
                data[temp] = 1;
        }
        for (map<int, int>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            printf("%d %d", iter->first, iter->second);
            cout << endl;
        }
    }
}