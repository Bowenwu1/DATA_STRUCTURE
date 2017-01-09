#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
 
using namespace std;

const int BIT = 60000 * 8;

string numToString(int num) {
	stringstream ss;
	ss << num;
	/* 0 ~ 9 */
	if (num < 10) {
		return "00" + ss.str();
	}
	/* 10 ~ 99 */
	if (num < 100) {
		return "0" + ss.str();
	}
	/* 100 ~ 255 */
	return ss.str();
}
vector<int> getOverlay(const string & son);
/* return -1 if there is no match */
int findSubstrIndex(const string & father, const string & son);

int main() {
	int length;
	while ((scanf("%d", &length) != EOF)) {
		string my;
		string compare;
		int temp;
		for (int i = 0; i < length; ++i) {
			cin >> temp;
			my += numToString(temp);
		}
		int com_length;
		cin >> com_length;
		for (int i = 0; i < com_length; ++i) {
			cin >> temp;
			compare += numToString(temp);
		}
		int result = findSubstrIndex(compare, my);
		if (result != string::npos) {
			cout << result / 3 << endl;
		} else {
			cout << "no solution" << endl;
		}
	}
}
