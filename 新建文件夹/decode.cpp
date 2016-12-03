#include <iostream>
#include <sstream>

using namespace std;
void repeatPrint(int times, char ch) {
	while (times--) {
		cout << ch;
	}
}
bool isChar(char ch) {
	if (ch <= 'z' && ch >= 'a')
		return true;
	return false;
}
bool isNum(char ch) {
	if (ch <= '9' && ch >= '0')
		return true;
	return false;
}
int strToNum(const string & s) {
	stringstream ss;
	ss << s;
	int a;
	ss >> a;
	return a;
}
void decode(const string & s) {
	char temp = s[0];
	for (int i = 0; i < s.length(); ++i) {
		if (isChar(s[i]))
			cout << s[i];
		else if (isNum(s[i])) {
			int indexTemp = i;
			for (indexTemp = i; indexTemp < s.length(); indexTemp++) {
				if (!isNum(s[indexTemp]))
					break;
			}
			repeatPrint(strToNum(s.substr(i, indexTemp - i)) - 1, temp);
			i = indexTemp - 1;
		}
		temp = s[i];
	}
	cout << endl;
}
int main() {
	string temp;
	while (1) {
		cin >> temp;
		if (temp == string("XXX"))
			break;
		decode(temp);
	}
}
