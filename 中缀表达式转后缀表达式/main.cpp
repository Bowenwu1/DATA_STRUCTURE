/* Created by Bowenwu
 * DS HOMEWORK
 * midfix to postfix
 * 2016.09.11
 */
 
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
		
		static string midfixToPostfix(const string & data) {
			string result;
			stack<char> sign;
			for (int i = 0; i < data.size(); ++i) {
				if (calculator::isNum(data[i])) {
					result += data[i];
				} else {
					if (sign.empty()) {
						sign.push(data[i]);
					} else {
						while (calculator::isPriority(sign.top(), data[i])) {
							result += sign.top();
							sign.pop();
							if (sign.empty())
								break;		
						}
						sign.push(data[i]);
					}
				}
			}
			while (!sign.empty()) {
				result += sign.top();
				sign.pop();
			}
			return result;
		}
	private:
		static int charToNum(const char & c) {
			if (c <= 'z' && c >= 'a')
				return c - 'a' + 1;
			else
				return 0;
		}
		static bool isNum(const char & c) {
			return c <= 'z' && c >= 'a'
				|| c <= 'Z' && c >= 'A';
		}
		static bool isPriority(const char & a, const char & b) {
			if ((a == '+' || a == '-') && (b == '*' || b == '/'))
				return false;
			return true;
		}
};


int main() {
	int CASE = 1;
	while (CASE--) {
		string data;
		cin >> data;
		cout << calculator::midfixToPostfix(data);
	}
}
