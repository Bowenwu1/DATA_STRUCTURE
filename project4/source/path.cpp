#include "path.hpp"

path::path() {
    totalLength = 0;
}

bool path::appendLastRoad(const road & newRoad) {
    if (0 == data.size()) {
        begin = newRoad.getSource();
        end = newRoad.getTarget();
        totalLength += newRoad.getLength();
        data.push_back(newRoad);
        return true;
    } else if (newRoad.getSource() == this->getEnd()) {
        end = newRoad.getTarget();
        totalLength += newRoad.getLength();
        data.push_back(newRoad);
        return true;
    }
    return false;
}

bool path::appendFirstRoad(const road & newRoad) {
    if (0 == data.size()) {
        begin = newRoad.getSource();
        end = newRoad.getTarget();
        totalLength += newRoad.getLength();
        data.push_back(newRoad);
        return true;
    } else if (newRoad.getTarget() == this->getBegin()) {
        begin = newRoad.getSource();
        totalLength += newRoad.getLength();
        data.push_front(newRoad);
        return true;
    }
    return false;
}

void path::deleteLastRoad() {
    if (1 == data.size()) {
        data.pop_back();
        begin.clear();
        end.clear();
        totalLength = 0;
    } else if (1 < data.size()) {
        road lastOne = *data.rbegin();
        end = lastOne.getSource();
        totalLength -= lastOne.getLength();
        data.pop_back();
    }
}

void path::deleteFirstRoad() {
    if (1 == data.size()) {
        data.pop_back();
        begin.clear();
        end.clear();
        totalLength = 0;
    } else if (1 < data.size()) {
        road FirstOne = *data.begin();
        begin = FirstOne.getTarget();
        totalLength -= FirstOne.getLength();
        data.pop_front();
    }
}

std::string path::getBegin() const { return begin; }
std::string path::getEnd() const { return end; }

std::vector<int> path::getRoadName() const {
    std::vector<int> result;
    for (auto iter = this->data.begin(); iter != this->data.end(); ++iter) {
        result.push_back((*iter).getLength());
    }
    return result;
}

std::vector<std::string> path::getDestinationName() const {
    std::vector<std::string> result;
    for (auto iter = this->data.begin(); iter != this->data.end(); ++iter) {
        result.push_back((*iter).getSource());
    }
    return result;
}

bool path::operator>(const path & other) const {
    return this->totalLength > other.totalLength;
}


bool path::operator<(const path & other) const {
    return this->totalLength < other.totalLength;
}


bool path::operator==(const path & other) const {
    return this->totalLength == other.totalLength;
}


bool path::operator<=(const path & other) const {
    return this->totalLength <= other.totalLength;
}


bool path::operator>=(const path & other) const {
    return this->totalLength >= other.totalLength;
}

/* the order of calculation matters */
path path::operator+(const path & other) {
    // I don't ensure two path can link correctly here
    // since it doesn't make any sense
    path result;
    result.totalLength = this->totalLength + other.totalLength;
    for (auto iter = this->data.begin(); iter != this->data.end(); ++iter)
        result.data.push_back(*iter);
    for (auto iter = other.data.begin(); iter != other.data.end(); ++iter)
        result.data.push_back(*iter);
    result.begin = this->begin;
    result.end = other.end;
    return result;
}

int path::getLength() const { return totalLength; }
