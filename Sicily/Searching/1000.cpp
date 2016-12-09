#include <set>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        set<int> a;
        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            a.insert(temp);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            // if (a.find(temp) != a.end())
            //     a.erase(temp);
            a.erase(temp);
        }
        set<int>::iterator iter = a.begin();
        if (iter != a.end())
            // cout << (*iter);
            printf("%d", (*iter));
        // bug occurs here
        else {
            cout << endl;
            continue;
        }
        for (++iter; iter != a.end(); ++iter) {
            // cout << " " << (*iter);
            printf(" %d", (*iter));
        }
        cout << endl;
    }
}