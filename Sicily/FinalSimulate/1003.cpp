#include <iostream>
#include <vector>
using namespace std;
int max = 0;
int height(vector<int> preOrder, vector<int> inOrder, int level);
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> preOrder(n);
        vector<int> inOrder(n);
        for (int i = 0; i < n; ++i)
            cin >> preOrder[i];
        for (int i = 0; i < n; ++i)
            cin >> inOrder[i];
        cout << height(preOrder, inOrder, -1) << endl;
    }
}
void printVector(const vector<int> & data) {
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i] << " ";
	}
	cout << endl;
}
int height(vector<int> preOrder, vector<int> inOrder, int level) {
    if (preOrder.size() == 1) return level + 1;
    if (preOrder.size() == 0) return level;
//    cout << "preOrder : " ; printVector(preOrder);
//    cout << "inOrder : "; printVector(inOrder);
    vector<int> leftPreOrder, leftInOrder;
    vector<int> rightPreOrder, rightInOrder;
    int root = preOrder[0];
    int i;
    for (i = 0; inOrder[i] != root; ++i) {
        leftPreOrder.push_back(preOrder[i + 1]);
        leftInOrder.push_back(inOrder[i]);
    }
    for (++i; i < preOrder.size(); ++i) {
        rightPreOrder.push_back(preOrder[i]);
        rightInOrder.push_back(inOrder[i]);
    }
    int a = height(leftPreOrder, leftInOrder, level + 1);
    int b = height(rightPreOrder, rightInOrder, level + 1);
    return (a > b ? a : b);
}
