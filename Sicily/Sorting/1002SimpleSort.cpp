#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p;
void prioritySort(vector<vector<int> > & data);
void printResult(const vector<vector<int> > & data);
bool pcomp(const vector<int> & a, const vector<int> & b) {
    return  a[0] < b[0];
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > data(n);
        for (int i = 0; i < n; ++i) data[i].resize(m + 1);
        // input data
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cin >> data[i][j];
            data[i][m] = i;
        }
        int queryCase;
        cin >> queryCase;
        while (queryCase--) {
            vector<vector<int> > priority(m);
            for (int i = 0; i < m; ++i) priority[i].resize(2);
            for (int i = 0; i < m; ++i) {
                cin >> priority[i][0];
                priority[i][1] = i;
            }
            sort(priority.begin(), priority.end(), pcomp);
            // for (int i = 0; i < m; ++i) cout << priority[i][0] << " " << priority[i][1] << endl;
            p.resize(m, 0);
            for (int i = 0; i < m; ++i)
                p[i] = priority[i][1];
            vector<vector<int> > ttt = data;
            prioritySort(ttt);
            printResult(ttt);
            if (queryCase) cout << endl;
        }
    }
}
bool whetherGreat(const vector<int> & a, const vector<int> & b) {
    int m = p.size();
    for (int i = 0; i < m; ++i) {
        if (a[p[i]] > b[p[i]])
            return false;
        else if (a[p[i]] < b[p[i]])
            return true;
    }
    return false;
}
void prioritySort(vector<vector<int> > & data) {
    stable_sort(data.begin(), data.end(), whetherGreat);
}

void printResult(const vector<vector<int> > & data) {
    int m = data[0].size() - 1;
    cout << data[0][m];
    for (int i = 1; i < data.size(); ++i)
        cout << " " << data[i][m];
}