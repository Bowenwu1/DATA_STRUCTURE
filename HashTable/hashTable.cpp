#include "hashTable.hpp"
using std::cout;
using std::endl;
hashTable::hashTable(int size):mod(size) {
    data.resize(mod, NULL);
}

hashTable::~hashTable() {
    for (int i = 0; i < mod; ++i)
        if (data[i]) delete data[i];
}

void hashTable::printTable() {
    for (int i = 0; i < mod; ++i) {
        cout << i << "# ";
        Node* temp = data[i];
        while (temp) {
            cout << temp->name << "(" << temp->number<<")  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

bool hashTable::insert(std::string name, std::string number) {
    try {
        int temp;
        if (this->find(name, number, temp)) throw 1;
        int index = this->hash(name, number);
        if (data[index]) {
            Node* temp = data[index];
            while (temp->next) temp = temp->next;
            temp->next = new Node(name, number);
        } else {
            data[index] = new Node(name, number);
        }
    }
    catch(...) {
        return false;
    }
    return true;
}

bool hashTable::find(std::string name, std::string number, int & times) {
    int index = this->hash(name, number);
    Node* temp = data[index];
    times = 0;
    while (temp) {
        ++times;
        if (temp->name == name && temp->number == number)
            return true;
        temp = temp->next;
    }
    return false;
}

bool hashTable::deleteElement(std::string name, std::string number) {
    int index = this->hash(name, number);
    Node* first = data[index];
    if (!first) return false;
    Node* second = first->next;
    // first one is the target element
    if (first->name == name && first->number == number) {
        data[index] = first->next;
        first->next = NULL;
        delete first;
        return true;
    }
    while (second) {
        if (second->name == name && second->number == number) {
            first->next = second->next;
            second->next = NULL;
            delete second;
            return true;
        }
        first = first->next;
        second = second->next;
    }
    return false;
}

int hashTable::hash(std::string name, std::string number) {
    int sum = 0;
    for (int i = 0; i < name.length(); ++i)
        sum += tolower(name[i]) - 'a';
    return sum % mod;
}