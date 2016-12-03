#include <iostream>
#include <string>
#include <bitset>
#include <stdio.h>
using namespace std;

const int BIT = 60000 * 8;
int main() {
	int length;
	while ((scanf("%d", &length) != EOF)) {
		bitset<BIT> my;
		int temp;
		for (int i = 0; i < length; ++i) {
			cin >> temp;
			my |= bitset<BIT>(temp) << i * 8;
		}
//			cout << "my :           " << my << endl;
		bitset<BIT> compare;
		for (int i = 0; i < length; ++i)
			compare |= bitset<BIT>(255) << i * 8;
//			cout << "compare :      " << compare << endl;
		bitset<BIT> com;
		int length_com;
		cin >> length_com;
		for (int i = 0; i < length_com; ++i) {
			cin >> temp;
			com |= bitset<BIT>(temp) << i * 8;
		}
//			cout  << "com :         " << com << endl;
		bool flag = false;
		for (int i = 0; i <= length_com - length; ++i) {
			// cout << (my << i * 8) << endl;
			if (i)
				compare <<= 8;
//			cout << "cycle " << i << endl;
//			cout << "compare :       " << compare << endl;
//			cout << "com     :       " << com << endl;
//			cout << "compare & com : " << (compare & com) << endl;
//			cout << "my << i * 8   : " << (my << i * 8) << endl;
			if ((compare & com) == (my << i * 8)) {
				flag = true;
				cout << i << endl;
				break;
			}
		}
		if (!flag)
			cout << "no solution" << endl;
	}
}
