/* Created by BowenWu
 * DS HOMEWORK
 * Bracket Matching
 * Stack
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int CASE;
	cin >> CASE;
	while (CASE--) {
		string data;
		cin >> data;
		stack<char> s1;
		bool match = true;
		for (int i = 0; i < data.size(); ++i) {
			// left bracket
			if ('(' == data[i] || '{' == data[i] || '[' == data[i]) {
				s1.push(data[i]);
			} else if (')' == data[i]) {
				if (s1.empty()) {
					match = false;
					break;
				} else if ('(' == s1.top()) {
					s1.pop();
				} else {
					match = false;
					break;
				}
			} else if ('}' == data[i]) {
				if (s1.empty()) {
					match = false;
					break;
				} else if ('{' == s1.top()) {
					s1.pop();
				} else {
					match = false;
					break;
				}
			} else if (']' == data[i]) {
				if (s1.empty()) {
					match = false;
					break;
				} else if ('[' == s1.top()) {
					s1.pop();
				} else {
					match = false;
					break;
				}
			}
		}
		if (match && s1.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}	
}
