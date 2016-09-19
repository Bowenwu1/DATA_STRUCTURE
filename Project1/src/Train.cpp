#include "Train.h"

Train::Train(int n):number(n) {}

int Train::getNum() const {
	return number;
}

void Train::setNum(int n) {
	number = n;
}

bool Train::operator>(const Train & other) {
	return this->number > other.number;
}

bool Train::operator<(const Train & other) {
	return this->number < other.number;
}

bool Train::operator==(const Train & other) {
	return this->number == other.number;
}

bool Train::operator<=(const Train & other) {
	return *this < other || *this == other;
}

bool Train::operator>=(const Train & other) {
	return *this > other || *this == other;
}
