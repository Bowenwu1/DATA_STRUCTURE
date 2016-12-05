#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
const int MAX_SIZE = 200;
int main() {
    int T;
    cin >> T;
    while (T--) {
        // initial
        map<string, int> nameMapIndexInGraph;
        vector<vector<int> > graph;
        graph.resize(MAX_SIZE);
        for (int i = 0; i < MAX_SIZE; ++i)
            graph[i].resize(MAX_SIZE, -1);
        // input data
        int n, weight;
        cin >> n;
        string source, target;
        int id = 0;
        for (int i = 0; i < n; ++i) {
            cin >> source >> target >> weight;
            if (nameMapIndexInGraph.find(source) == nameMapIndexInGraph.end())
                nameMapIndexInGraph[source] = id++;
            if (nameMapIndexInGraph.find(target) == nameMapIndexInGraph.end())
                nameMapIndexInGraph[target] = id++;
            graph[nameMapIndexInGraph[source]][nameMapIndexInGraph[target]] = weight;
            graph[nameMapIndexInGraph[target]][nameMapIndexInGraph[source]] = weight;
        }
        cin >> source >> target;
        if (source == target) {
            cout << 0 << endl;
            continue;
        }
        if (nameMapIndexInGraph.find(source) == nameMapIndexInGraph.end() || nameMapIndexInGraph.find(target) == nameMapIndexInGraph.end()) {
            cout << -1 << endl;
            continue;
        }
        // floyd algorithm
        // now id is the size of our graph
        for (int i = 0; i < id; ++i)
            graph[i][i] = 0;
        for (int k = 0; k < id; ++k)
            for (int i = 0; i < id; ++i)
                for (int j = 0; j < id; ++j) {
                    if (graph[i][k] != -1 && graph[k][j] != -1) {
                        if (graph[i][j] > graph[i][k] + graph[k][j] || graph[i][j] == -1)
                            graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
        cout << graph[nameMapIndexInGraph[source]][nameMapIndexInGraph[target]] << endl;
    }
}