#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;
#define DEBUG
#undef DEBUG
int main() {
	int CASE;
	cin >> CASE;
	while (CASE--) {
		int n;
		cin >> n;
		queue<int> data;
		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			data.push(temp);
		}
		stack<int> s1, s2, s3;
		s3.push(0);
		string operation;
		bool whether_continue = false;
		while (1) {

			// operation b
			if (!s1.empty()) {
				if (s1.top() == s3.top() + 1) {
					s3.push(s1.top());
					s1.pop();
					operation += "b ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				}
			}

			// operation a
			if (!data.empty()) {
				if (s1.empty()) {
					s1.push(data.front());
					data.pop();
					operation += "a ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				} else if (data.front() < s1.top()) {
					s1.push(data.front());
					data.pop();
					operation += "a ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				}
			}

			// operation d
			if (!s2.empty()) {
				if (s2.top() == s3.top() + 1) {
					s3.push(s2.top());
					s2.pop();
					operation += "d ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				}
			}

			//operation c
			if (!data.empty()) {
				if (s2.empty()) {
					s2.push(data.front());
					data.pop();
					operation += "c ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				}
				else if (data.front() < s2.top()) {
					s2.push(data.front());
					data.pop();
					operation += "c ";
#ifdef DEBUG
					cout << operation << endl;
#endif
					continue;
				}
			}
			if (!whether_continue) {
				if (s3.size() == n + 1) {
					cout << operation << endl;
					break;
				}
				else {
					cout << 0 << endl;
					break;
				}
			}
			whether_continue = false;
		}
	}
	return 0;
}
