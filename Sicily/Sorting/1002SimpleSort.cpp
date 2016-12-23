#include <iostream>
#include <vector>
using namespace std;
void prioritySort(vector<vector<int> > & data, vector<int> & p);
void printResult(const vector<vector<int> > & data);
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
            for (int i = 0; i < m; ++i)
                for (int j = i + 1; j < m; ++j) {
                    if (priority[i][0] > priority[j][0])
                        swap(priority[i], priority[j]);
                }
            vector<int> p(m);
            for (int i = 0; i < m; ++i)
                p[i] = priority[i][1];
            prioritySort(data, p);
            printResult(data);
            if (queryCase) cout << endl;
            vector<int> temp(m);
            temp[0] = m;
            prioritySort(data, temp);
        }
    }
}
bool whetherGreat(const vector<int> & a, const vector<int> & b, const vector<int> & p) {
    int m = p.size();
    for (int i = 0; i < m; ++i) {
        if (a[p[i]] > b[p[i]])
            return true;
        else if (a[p[i]] < b[p[i]])
            return false;
    }
    return false;
}
void prioritySort(vector<vector<int> > & data, vector<int> & p) {
    int size = data.size();
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (whetherGreat(data[i], data[j], p))
                swap(data[i], data[j]);
}

void printResult(const vector<vector<int> > & data) {
    int m = data[0].size() - 1;
    cout << data[0][m];
    for (int i = 1; i < data.size(); ++i)
        cout << " " << data[i][m];
}