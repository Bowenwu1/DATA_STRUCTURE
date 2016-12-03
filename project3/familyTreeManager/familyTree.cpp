#include"familyTree.h"

int familyTree::idCount = 0;
familyTree::familyTree(string name, bool isMale, string birthday) {
    root = new Person(name, birthday, isMale);
    idCount++;
}

void familyTree::destroy(Person *subTree) {
    if (subTree != NULL) {
        destroy(subTree->leftOne);
        destroy(subTree->rightOne);
        delete subTree;
    }
}
familyTree::~familyTree() {
    destroy(root);
}

void familyTree::print(Person *subFamily) const {
    if (NULL == subFamily)
		return;
    cout << subFamily->name << ' ';    //  husband
    Person *p = subFamily;
	if (p->rightOne != NULL) {
		while (p->rightOne != NULL) {
			p = p->rightOne;
		}
		cout << p->name;    //  present wife
	}
	cout << endl;
    cout << "their children(or child)'s family: {" << endl;
    p = subFamily;
    while (p->rightOne != NULL) {
        p = p->rightOne;

        Person *q = p;
        while (q->leftOne != NULL) {
            q = q->leftOne;
            print(q);
        }
    }
    cout << '}' << endl;

}

bool familyTree::addBaby(Person newBaby, int motherId) {
    Person* lastChildren = findLastChildren(motherId);
    // validate
    if (lastChildren == NULL)
        return false;
    lastChildren->leftOne = new Person(newBaby);
	lastChildren->leftOne->id = idCount++;
    return true;
}

bool familyTree::addWife(Person newWife, int loverId) {
    Person* lastWife = findLastWife(loverId);
    // validate
    if (lastWife == NULL)
        return false;
    lastWife->rightOne = new Person(newWife);
	lastWife->rightOne->isMarried = true;
	lastWife->rightOne->id = idCount++;
	lastWife->rightOne->isAlive = true;
	lastWife->rightOne->isMale = false;
	findSomeone(loverId)->isMarried = true;
    return true;
}

int familyTree::getIdByName(string name) {
	Person* temp = this->findSomeoneByName(name);
	if (temp) {
		return temp->id;
	}
	return -1;
}
Person* familyTree::findSomeone(int id,  Person* start) {
    // start from root
    if (start == NULL)
        start = root;
    // check itself
    if (start->id == id)
        return start;
    // check leftOne
    if (start->leftOne) {
        Person* temp = this->findSomeone(id, start->leftOne);
        if (temp)
            return temp;
    }
    if (start->rightOne)
        return this->findSomeone(id, start->rightOne);
    return NULL;
}

Person* familyTree::findSomeoneByName(string name, Person* start) {
	// start from root
	if (start == NULL)
		start = root;
	// check itself
	if (start->name == name)
		return start;
	// check leftOne
	if (start->leftOne) {
		Person* temp = this->findSomeoneByName(name, start->leftOne);
		if (temp)
			return temp;
	}
	if (start->rightOne)
		return this->findSomeoneByName(name, start->rightOne);
	return NULL;
}
Person* familyTree::findLastChildren(int motherId) {
    Person* mother = this->findSomeone(motherId);
    if (mother) {
        if (mother->isMale == false) {
            while (mother->leftOne)
                mother = mother->leftOne;
            return mother;
        } else {
            return NULL;
        }
    }
    return NULL;
}

Person* familyTree::findLastWife(int loverId) {
    Person* lover = this->findSomeone(loverId);
    if (lover) {
        if (lover->isMale) {
            while (lover->rightOne)
                lover = lover->rightOne;
            return lover;
        } else {
            return NULL;
        }
    }
    return NULL;
}

bool familyTree::queryWife(int loverId) {
    Person *p = findSomeone(loverId);

    if (NULL == p)
        return false;

    while (p->rightOne != NULL) {
        p = p->rightOne;
        cout << p->name << ' ' << p->id << endl;
    }

    return true;
}

bool familyTree::queryChild(int fatherId) {
    Person *p = findSomeone(fatherId);

    if (NULL == p)
        return false;

    while (p->rightOne != NULL) {
        p = p->rightOne;

        Person *q = p;
        while (q->leftOne != NULL) {
            q = q->leftOne;
            cout << q->name << ' ' << q->id << endl;
        }
    }

    return true;
}

bool familyTree::changeName(int userId, string newName) {
	Person* temp = this->findSomeone(userId);
	if (temp)
		return false;
	temp->name = newName;
	return true;
}

bool familyTree::changeGender(int userId, bool newGender) {
	Person* temp = this->findSomeone(userId);
	if (!temp)
		return false;
	temp->isMale = newGender;
	return true;
}

bool familyTree::die(int userId)
{
	Person* temp = this->findSomeone(userId);
	if (!temp)
		return false;
	temp->isAlive = false;
	return true;
}
