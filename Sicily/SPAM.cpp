#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readData(vector<string> & data) {
	string temp;
	while (/*cin >> temp*/ getline(cin, temp)) {
		data.push_back(temp);
	}
}
bool checkChar(const char & ch) {
	if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z') ||
         (ch >= '0'&&ch <= '9') || ch == '-'||ch == '_') {
            return true;
     }
     return false;
}
//bool verifyName(const string & s) {
//	if (s.length() == 0)
//		return false;
//	for (int i = 0; i < s.length(); ++i) {
//		if (!checkChar(s[i]))
//			return false;
//	}
//	return true;
//}
//bool verifyAddress(const string & s) {
//	if (s.length() == 0)
//		return false;
//	bool expectDot = false;
//	for (int i = s.length() - 1; i > -1; ++i) {
//		if (expectDot) {
//			if (checkChar(s[i]))
//				continue;
//			else {
//				if (s[i] == '.') {
//					expectDot = false;
//					continue;
//				}
//			}
//		} else {
//			if (s[i] == '.')
//				return false;
//			else if (!checkChar(s[i]))
//				return false;
//		}
//	}
//	return true;
//}
//void printEmail(const string & s1, const string & s2) {
//	if (!verifyName(s1))
//		cout << "verifyNameFail:    " << s1 << endl;
//	if (!verifyAddress(s2))
//		cout << "verifyAddressFail: " << s2 << endl;
//	if (verifyName(s1) && verifyAddress(s2)) {
//		cout << s1 << "@" << s2 << endl;
//	}
//}
//// print the email at the mean time 
//void generateEmail(const string & s) {
//	// index for char @
//	vector<int> index;
//	index.push_back(0);
//	for (int i = 0; i < s.length(); ++i) {
//		if (s[i] == '@')
//			index.push_back(i);
//	}
//	if (index.size() == 1)
//		return;
//	if (index.size() == 2) {
//		printEmail(s.substr(0, index[1]), s.substr(index[1] + 1));
//		return;
//	}
//	// first one
//	printEmail(s.substr(0, index[1]), s.substr(index[1] + 1, index[2] - index[1] - 1));
//	for (int i = 1; i < index.size() - 1; i++) {
//		printEmail(s.substr(index[i - 1] + 1, index[i] - index[i - 1] - 1),
//					s.substr(index[i] + 1, index[i + 1] - index[i] - 1));
//	}
//	// last one
//	int temp = index.size() - 1;
//	printEmail(s.substr(index[temp - 1], index[temp] - index[temp - 1] - 1),
//				s.substr(index[temp]));
//}
void generateEmail(const string & s) {
	int begin = 0, end = 0;
	for (int i = 0; i < s.length() - 1; ++i) {
		// now begin search
		if (s[i] == '@' && i != 0 && checkChar(s[i - 1]) && checkChar(s[i + 1])) {
			// move forward
				for (begin = i - 1; begin > -1; --begin) {
					if (s[begin] == '.' && s[begin + 1] == '.')
						break;
					if (s[begin] != '.' && !checkChar(s[begin]))
						break;
				}
				if (s[begin + 1] == '.') begin++;
				begin++;
				if (begin == i)
					break;
			// move backward
				for (end = i + 1; end < s.length(); ++end) {
					if (s[end] == '.' && s[end - 1] == '.')
						break;
					if (s[end] != '.' && !checkChar(s[end]))
						break;
				}
				if (s[end - 1] == '.') end--;
				end--;
				if (end == i)
					break;
			
			cout << s.substr(begin, end - begin + 1) << endl;
		}
	}
}
int main() {
	vector<string> data;
	readData(data);
	for (int i = 0; i < data.size(); ++i) {
		generateEmail(data[i]);
	}
}
