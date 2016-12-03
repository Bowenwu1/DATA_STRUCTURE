#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int getVerifyNum(const string & t);

int main() {
	string input;
	while (cin >> input){
		int result = getVerifyNum(input);
		cout << input << "-";
		if (result != 10)
			cout << result;
		else
			cout << "X";
		cout << endl;
	}
	return 0;
}

int getVerifyNum(const string & t) {
	int result = 0;
	int plus = 10;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] >= '0' && t[i] <= '9')
			result += (t[i] - '0') * (plus--);
	}
	for (int i = 0;;++i)
		if ((result + i) % 11 == 0)
			return i;
}
