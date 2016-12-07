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
    } else if (newRoad.getSource() == this.getEnd()) {
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
    } else if (newRoad.getTarget() == this.getBegin()) {
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

std::vector<std::string> getRoadName() const {
    std::vector<std::string> result;
    
}