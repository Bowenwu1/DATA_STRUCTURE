#include <iostream>
#include <vector>
using namespace std;
bool whetherTwice(int a, int b) {
	if (a == b * 2)
		return true;
	if (b == a * 2)
		return true;
	return false;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int result = 0;
		cin >> n;
		vector<int> data;
		data.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (whetherTwice(data[i], data[j]))
					result++;
			}
		}
		cout << result << endl;
	}
}
