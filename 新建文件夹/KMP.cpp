/* KMP algorithm */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int length;
	while ((scanf("%d", &length) != EOF)) {
		vector<int> pattern;
		pattern.resize(length);
		for (int i = 0; i < length; ++i) {
			cin >> pattern[i];
		}
		int myLength = 0;
		cin >> myLength;
		vector<int> data;
		data.resize(myLength);
		for (int i = 0; i < myLength; ++i) {
			cin >> data[i];
		}
		
	}
}
