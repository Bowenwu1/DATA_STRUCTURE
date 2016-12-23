#include <iostream>
#include <string>
#include <set>
using namespace std;
void toLowerCase(string & a) {
    for (int i = 0; i < a.length(); ++i)
        a[i] = tolower(a[i]);
}
int main() {
    int n, m;
    while (1) {
        cin >> n;
        if (!n) return 0;
        cin >> m;
        set<string> data;
        string temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            toLowerCase(temp);
            data.insert(temp);
        }
        for (int i = 0; i < m; ++i) {
            cin >> temp;
            toLowerCase(temp);
            data.erase(temp);
        }
        cout << data.size() << endl;
    }
}