#include <iostream>
#include <stack>
#include <string>
#include <iomanip>


using namespace std;

class calculator {
	public:
		static double cal (const string & data) {
			stack<double> number;
			for (int i = 0; i < data.length(); ++i) {
				if (calculator::isNum(data[i])) {
					number.push(calculator::charToNum(data[i]));
				} else {
					if (data[i] == '+') {
						double a, b;
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						number.push(a + b);
					} else if (data[i] == '-') {
						double a, b;
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						number.push(b - a);
					} else if (data[i] == '*') {
						double a, b;
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						number.push(a * b);
					} else if (data[i] == '/') {
						double a, b;
						a = number.top();
						number.pop();
						b = number.top();
						number.pop();
						number.push(b / a);
					}
				}
			}
			return number.top();
	}
	private:
		static int charToNum(const char & c) {
			if (c <= 'z' && c >= 'a')
				return c - 'a' + 1;
			else
				return 0;
		}
		static bool isNum(const char & c) {
			return c <= 'z' && c >= 'a';
		}
};

int main() {
	int CASE;
	cin >> CASE;
	while (CASE--) {
		string data;
		cin >> data;
		cout << fixed << setprecision(2) << calculator::cal(data) << endl;
	}
}
