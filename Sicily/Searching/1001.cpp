#include <iostream>
using namespace std;

int binSearch(const int s[], const int size, const int target) {
    int position = size / 2;
    int begin = 0;
    int end = size;
    while (end - begin > 1) {
        position = (begin + end) / 2;
        // cout << "position : " << position << " begin : " << begin << " end : " << end << endl;
        if (target > s[position]) {
            begin = position;
            continue;
        } else if (target < s[position]) {
            end = position;
        } else if (target == s[position]) {
            break;
        }
    }
    if (target == s[position]) {
        for (int i = position; i + 1 < size; ++i) {
            if (s[i + 1] != target)
                return i;
        }
        return size - 1;
    } else
        return -1;
}

int main() {
    int s[10] = {0,1,1,2,3,3,6,6, 10, 10};

cout << binSearch(s,10,3) << endl;  //输出5

cout << binSearch(s,10,10) << endl;  //输出-1
}