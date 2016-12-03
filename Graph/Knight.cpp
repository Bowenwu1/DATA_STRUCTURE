#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int** result;
bool** visited;
int charToNumber(char a) {
    return a - 'a';
}

void recordResult(string index, int res) {
    int i = charToNumber(index[0]);
    int j = index[1] - '1';
    result[i][j] = res;
//    cout << index << " is " << res << endl;
}

int getResult(string index) {
    int i = charToNumber(index[0]);
    int j = index[1] - '1';
    return result[i][j];
}

bool isValid(char i, char j) {
    return (i >= 'a' && i <= 'h' && j >= '1' && j <= '8');
}
bool isVisited(char a, char b) {
	int i = a - 'a';
    int j = b - '1';
    return visited[i][j];
}
void visit(char a, char b) {
    int i = a - 'a';
    int j = b - '1';
    visited[i][j] = true;
}
void init() {
//    result.resize(8);
//    for (int i = 0; i < 8; ++i)
//        result[i].resize(8, -1);
//    for (int i = 0; i < 8; ++i)
//    	for (int j = 0; j < 8; ++j)
//    		result[i][j] = -1;
	if (result == NULL) {
		result = new int*[8];
        visited = new bool*[8];
		for (int i = 0; i < 8; ++i) {
			result[i] = new int[8];
            visited[i] = new bool[8];
        }
	}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
            result[i][j] = 0;
            visited[i][j] = false;
        }
}
void moveAndPushIntoQueue(queue<string> & data, string index, int i, int j) {
    char colIndex = index[0] + i;
    char rowIndex = index[1] + j;
    if (isValid(colIndex, rowIndex) && !isVisited(colIndex, rowIndex)) {
                string temp;
                temp += colIndex;
                temp += rowIndex;
                data.push(temp);
                visit(colIndex, rowIndex);
//                cout << "visit " << temp << endl;
				// cout << index << endl;
//				cout << "result is " << getResult(index) << endl;
				int t = getResult(index);
				t++;
//				cout << "result + 1 is " << t << endl;
                recordResult(temp, getResult(index) + 1);
            }
}

int main() {
    int TEST;
    cin >> TEST;
    while (TEST--) {
        init();
        string str, end;
        cin >> str >> end;
        queue<string> data;
        data.push(str);
        recordResult(str, 0);
        while (!data.empty()) {
            string lastIndex = data.front();
            data.pop();
            if (lastIndex == end) {
                cout << "To get from " << str << " to " << end << " takes " << getResult(end) <<  " knight moves." << endl;
                break;
            }
            moveAndPushIntoQueue(data, lastIndex, -2, -1);
            moveAndPushIntoQueue(data, lastIndex, -1, -2);
            moveAndPushIntoQueue(data, lastIndex, -2, +1);
            // if (isValid(lastIndex[0] - 1, lastIndex[0] + 2)) {
            //     recordResult(lastIndex[0] - 1, lastIndex[0] + 2, getResult(lastIndex) + 1);
            //     string temp;
            //     temp += lastIndex[0] - 1;
            //     temp += lastIndex[0] + 2;
            //     data.push(temp);
            // }
            moveAndPushIntoQueue(data, lastIndex, -1, +2);
            // // move leftdown
            // if (isValid(lastIndex[0] + 2, lastIndex[0] - 1)) {
            //     recordResult(lastIndex[0] + 2, lastIndex[0] - 1, getResult(lastIndex) + 1);
            //     string temp;
            //     temp += lastIndex[0] + 2;
            //     temp += lastIndex[0] - 1;
            //     data.push(temp);
            // }
            moveAndPushIntoQueue(data, lastIndex, +2, -1);
            // if (isValid(lastIndex[0] + 1, lastIndex[0] - 2)) {
            //     recordResult(lastIndex[0] + 1, lastIndex[0] - 2, getResult(lastIndex) + 1);
            //     string temp;
            //     temp += lastIndex[0] + 1;
            //     temp += lastIndex[0] - 2;
            //     data.push(temp);
            // }
            moveAndPushIntoQueue(data, lastIndex, +1, -2);
            // // move rightdown
            // if (isValid(lastIndex[0] + 2, lastIndex[0] + 1)) {
            //     recordResult(lastIndex[0] + 2, lastIndex[0] + 1, getResult(lastIndex) + 1);
            //     string temp;
            //     temp += lastIndex[0] + 2;
            //     temp += lastIndex[0] + 1;
            //     data.push(temp);
            // }
            moveAndPushIntoQueue(data, lastIndex, +2, +1);
            // if (isValid(lastIndex[0] + 1, lastIndex[0] + 2)) {
            //     recordResult(lastIndex[0] + 1, lastIndex[0] + 2, getResult(lastIndex) + 1);
            //     string temp;
            //     temp += lastIndex[0] + 1;
            //     temp += lastIndex[0] + 2;
            //     data.push(temp);
            // }
            moveAndPushIntoQueue(data, lastIndex, +1, +2);
        }
    }
}
