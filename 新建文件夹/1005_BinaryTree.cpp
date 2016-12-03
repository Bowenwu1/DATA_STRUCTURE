#include <iostream>
#include <vector>

using namespace std;

struct Node {
	char c;
	int left;
	int right;
	int father;
};

struct Node data[1001];

void init() {
	for (int i = 0; i < 1001; ++i) {
		data[i].c = '0';
		data[i].left = 0;
		data[i].right = 0;
		data[i].father = 0;
	}
}

void preOrder(int index) {
	if (data[index].c != '0') {
		cout << data[index].c;
		preOrder(data[index].left);
		preOrder(data[index].right);
	}
}
int main() {
	while (1) {
		init();
		int n;
		if (!(cin >> n))
			break;
		while(n--) {
			int index;
			cin >> index;
			char d;
			cin >> d;
			int l, r;
			cin >> l >> r;
			data[index].c = d;
			data[index].left = l;
			data[index].right = r;
			data[l].father = index;
			data[r].father = index;
		}
		/* find root Node */
		int rootIndex = 1;
		while (1) {
			if (data[rootIndex].c != '0') {
				if (data[rootIndex].father == 0) {
					break;
				} else {
					rootIndex = data[rootIndex].father;
				}
			} else {
				++rootIndex;
			}
		}
		preOrder(rootIndex);
		cout << endl;
	}
}
