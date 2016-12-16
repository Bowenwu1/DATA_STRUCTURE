#ifndef HASTTABLE_HPP
#define HASTTABLE_HPP
#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
class hashTable {
    private:
        struct Node {
            std::string name;
            std::string number;
            Node* next;
            Node(std::string n, std::string no, Node* next_ = NULL):
                name(n), number(no), next(next_) {}
            ~Node() {
                if (next) delete next;
            }
        };
        int mod;
        std::vector<Node*> data;
        int hash(std::string name, std::string number);
    public:
        hashTable() = delete;
        hashTable(int size);
        ~hashTable();

        void printTable();

        bool insert(std::string name, std::string number);
        bool find(std::string name, std::string number, int & times);
        bool deleteElement(std::string name, std::string number);        
};
#endif