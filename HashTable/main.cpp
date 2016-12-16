#include "hashTable.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    bool whetherInit = false;
    bool whetherContinue = true;
    hashTable test(10);
    while (whetherContinue) {
        cout << "1   --init" << endl
             << "2   --insert" << endl
             << "3   --delete" << endl
             << "4   --print" << endl
             << "5   --findElement" << endl;
        int op;
        cin >> op;
        switch(op) {
            case 1:
                {
                    if (whetherInit) {
                        cout << "you have init!" << endl;
                        break;
                    }
                    whetherInit = true;
                    fstream fs("data.txt", fstream::in);
                    string name, number;
                    while (fs >> name >> number) {
                        test.insert(name, number);
                    }
                    fs.close();
                }
                break;
            case 2:
                {
                    cout << "please input name and number" << endl
                        << "~$[insert]";
                    string name, number;
                    if (test.insert(name, number)) {
                        cout << "~$ success!" << endl;
                    } else {
                        cout << "~$ fail!" << endl;
                    }
                }
                break;
            case 3:
                {
                    cout << "please input name and number" << endl
                        << "~$[delete]";
                    string name, number;
                    if (test.deleteElement(name, number)) {
                        cout << "~$ success!" << endl;
                    } else {
                        cout << "~$ fail!" << endl;
                    }

                }
                break;
            case 4:
                {
                    cout << "~$[print]" << endl;
                    test.printTable();
                }
                break;
            case 5:
                {
                    cout << "please input name and number" << endl
                        << "~$[find]";
                    string name, number;
                    int times;
                    if (test.find(name, number, times)) {
                        cout << "~$ success! and cost " << times << " compare." << endl;
                    } else {
                        cout << "~$ fail!" << endl;
                    }
                    
                }
                break;
            case 6:
                {
                    whetherContinue = false;
                }
                break;
            default:
                cout << "wrong input! input again" << endl;
                break;
        }
    }
    cout << "bye bye" << endl;
}