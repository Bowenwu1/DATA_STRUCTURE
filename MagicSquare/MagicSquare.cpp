#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class MagicSquare {
  private:
    vector<vector<int>> square;
    int size;
  public:
    MagicSquarez(int s):size(s) {
        if (size <= 1) {
            // if the parm is illegal
            // set it to 2
            size = 2;
        }
        square = vector<vector<int>>(size, vector<int>(size, 0));
        this->setSquare(size);
    }
    void setSquare(int size) {
        if (size % 2)
            this->setOdd();
        else if (size % 4)
            this->set4();
        else if (size % 4 == 2)
            this->set2();
    }
  private:
    void setOdd() {
            int r = 0, c = 0;
        for (int i = 1; i <= size * size; i++) {
            if (1 == i) {
                square[0][size / 2] = 1;
                r = 0;
                c = size / 2;
            } else {
                // on the top size and not in corner
                if (0 == r && size - 1 != c) {
                    if (square[size - 1][c + 1])
                        r++;
                    else {
                        r = size - 1;
                        c++;
                    }
                // on the top and in corner
                } else if (0 == r && size - 1 == c) {
                    r = r + 1;
                } else if (size - 1 == c) {
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
                // cout << "size : " << r << " col: " << c << " " << i << endl;
                square[r][c] = i;
            }
        }
    }
};