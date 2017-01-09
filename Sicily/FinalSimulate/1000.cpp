#include <stack>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool whetherLeft(char a) {
    return (a == '(' || a == '[' || a == '{');
}
bool whetherRight(char a) {
    return (a == ')' || a == '}' || a == ']');
}
bool whetherMatch(char a, char b) {
    if (a == '(') return b == ')';
    if (a == '{') return b == '}';
    if (a == '[') return b == ']';
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        string input;
        cin >> input;
        stack<char> temp;
        bool flag = true;
        for (int i = 0; i < input.length(); ++i) {
                if (whetherLeft(input[i])) {
                    temp.push(input[i]);
                } else if (whetherRight(input[i])) {
                    if (!temp.empty()) {
                        if (!whetherMatch(temp.top(), input[i])) {
                            flag = false;
                            break;
                        } else {
                            temp.pop();
                        }
                    } else {
                    	flag = false;
                    	break;
					}
                }
        }
        if (!temp.empty()) flag = false;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
