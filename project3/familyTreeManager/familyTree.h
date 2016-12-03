#ifndef FAMILYTREE_H_INCLUDED
#define FAMILYTREE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

struct Person {
    int id;
    string name;
    string birthday;
    bool isMale, isAlive, isMarried;
    Person *leftOne, *rightOne;

    Person(string n, string b, bool iMal, bool iAli = true,
    bool iMar = false, Person *l = NULL, Person *r = NULL) :
    id(0), name(n), birthday(b), isMale(iMal), isAlive(iAli), isMarried(iMar),
    leftOne(l), rightOne(r) {}
	bool changeName(string newName) {
		name = newName;
		return true;
	}
	bool changeGender(bool newGender) {
		isMale = newGender;
	}
	bool marrary(bool newIsMarried) {
		isMarried = newIsMarried;
	}
};

class familyTree {
public:
    familyTree(string name, bool isMale, string birthday);
    ~familyTree();
    void print(Person *subFamily) const;
    bool addBaby(Person newBaby, int motherId);
    bool addWife(Person newWife, int loverId);
	int getIdByName(string name);
    bool queryWife(int loverId);
    bool queryChild(int fatherId);
	bool changeName(int userId, string newName);
	bool changeGender(int userId, bool newGender);
	bool die(int userId);
	Person* getRoot() const {
		return root;
	}
    static int idCount;
private:
    void destroy(Person *subTree);
    Person* findSomeone(int id, Person* start = NULL);
	Person* findSomeoneByName(string name, Person* start = NULL);
    Person* findLastChildren(int motherId);
    Person* findLastWife(int loverId);
    Person *root;
};

#endif // FAMILYTREE_H_INCLUDED
