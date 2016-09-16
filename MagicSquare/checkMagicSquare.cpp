/* Created by BowenWu
 * For check whether a
 * square is magic square
 * c++11
 * 2016.09.03
 */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    cout << "Please input the size of your square: ";
    int size;
    cin >> size;
    if (size <= 0) {
        cout << "Please input a legal size!" << endl;
        return 0;
    }
    vector<vector<int>> square(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> square[i][j];
    int sum = 0;
    int sum_temp = 0;
    for (int i = 0; i < size; i++) {
        sum += square[0][i];
    }
    // check row
    for (int i = 0; i < size; i++) {
        sum_temp = 0;
        for (int j = 0; j < size; j++)
            sum_temp += square[i][j];
        if (sum_temp != sum) {
            cout << "It's not a magic square!" << endl;
            return 0;
        }
    }
    // check col
    for (int i = 0; i < size; i++) {
        sum_temp = 0;
        for (int j = 0; j < size; j++)
            sum_temp += square[j][i];
        if (sum_temp != sum) {
            cout << "It's not a magic square!" << endl;
            return 0;
        }
    }
    // check diagonal
    sum_temp = 0;
    for (int i = 0; i < size; i++) {
        sum_temp += square[i][i];
    }
    if (sum_temp != sum) {
            cout << "It's not a magic square!" << endl;
            return 0;
    }
    sum_temp = 0;
    for (int i = 0; i < size; i++) {
        sum_temp += square[i][size - 1 - i];
    }
    if (sum_temp != sum) {
            cout << "It's not a magic square!" << endl;
            return 0;
    }
    cout << "It is a magic square!" << endl;
    return 0;
}