#include <iostream>
using namespace std;

int binSearch(const int s[], const int size, const int target) {
    int position = size / 2;
    int begin = 0;
    int end = size;
    while (end > begin) {
        cout << "position : " << position << " begin : " << begin << " end : " << end << endl;
        position = (begin + end) / 2;
        if (target <= s[position]) {
            begin = position;
            continue;
        } else if (target > s[position]) {
            end = position;
        }
    }
    if (target == s[position])
        return position;
    else
        return -1;
}

int main() {
    int s[8] = {0,1,1,3,3,3,6,6};

cout << binSearch(s,8,3) << endl;  //输出5

cout << binSearch(s,8,4) << endl;  //输出-1
}