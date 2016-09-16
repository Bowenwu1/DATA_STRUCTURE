/* Created by BowenWu
 * Please use c++11 to complie
 * this code.
 * 2016.09.03
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// only for magic square of odd rows

int main() {
    int row;
    cin >> row;
    if (0 == row % 2) {
        cout << "Please input a odd number!" << endl;
        return 0;
    }
    vector<vector<int>> square(row, vector<int>(row, 0));
    int r = 0, c = 0;
    for (int i = 1; i <= row * row; i++) {
        if (1 == i) {
            square[0][row / 2] = 1;
            r = 0;
            c = row / 2;
        } else {
            // on the top row and not in corner
            if (0 == r && row - 1 != c) {
                if (square[row - 1][c + 1])
                    r++;
                else {
                    r = row - 1;
                    c++;
                }
            // on the top and in corner
            } else if (0 == r && row - 1 == c) {
                r = r + 1;
            } else if (row - 1 == c) {
                if (square[r - 1][0]) {
                    r++;
                } else {
                    r = r - 1;
                    c = 0;
                }
            } else {
                if (square[r - 1][c + 1]) {
                    r++;
                } else {
                    r--;
                    c++;
                }
            }
            // cout << "row : " << r << " col: " << c << " " << i << endl;
            square[r][c] = i;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++)
            cout << setw(4) << square[i][j] << ' ';
        cout << endl;
    }
    return 0;
}