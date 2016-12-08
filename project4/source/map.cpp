#include "Map.hpp"

Map::Map(std::string dPath, std::string rPath) {
    std::fstream fs(dPath);
    int id = 0;
    /* destination file format :
     * name (space) description
     */
    if (!fs.is_open()) {
        whetherSuccessInitialize = false;
        return;
    }
    while (!fs.eof()) {
        std::string name, description;
        fs >> name >> description;
        destination temp(name, description);
        destinationInfo.push_back(temp);
        if (destinationNameToIndex.find(name) == destinationNameToIndex.end())
            destinationNameToIndex[name] = id++;
    }
    fs.close();
    fs.open(rPath);
    if (!fs.is_open()) {
        whetherSuccessInitialize = false;
        return;
    }
    // input road information
    /* road file format :
     * source target length whetherWalk(1 or 0) whetherDrive(1 or 0)
     * for now, we define a road is two-way
     */
     int size = destinationNameToIndex.size();
     adjaMatrix.resize(size);
     for (int i = 0; i < size; ++i)
        adjaMatrix[i].resize(size);
    while (!fs.eof()) {
        std::string source, target;
        int length;
        bool whetherWalk, whetherDrive;
        fs >> source >> target >> length >> whetherWalk >> whetherDrive;
        road temp(source, target, length, whetherWalk, whetherDrive);
        int i = destinationNameToIndex[source];
        int j = destinationNameToIndex[target];
        adjaMatrix[i][j] = adjaMatrix[j][i] = temp;
    }
    fs.close();
    whetherSuccessInitialize = true;
}

bool Map::checkWhetherSuccessInitialize() const {
    return whetherSuccessInitialize;
}

path Map::getShortestPath(std::string begin, std::string end, bool canWalk, bool canDriveCar) const {
    if (whetherSuccessInitialize) {
        // first use Floyd
        // this method is really stupid, and I just want to finish it first
        // Finish it and Improve it!
        std::vector<std::vector<road> > temp;
        int size = destinationNameToIndex.size();
        temp.resize(size);
        for (int i = 0; i < size; ++i)
            temp[i].resize(i);
        // init temp matrix
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                if (adjaMatrix[i][j].getLength() && adjaMatrix[i][j].canWalk() == canWalk
                    && adjaMatrix[i][j].canDriveCar() == canDriveCar) {
                    temp[i][j].appendLastRoad(adjaMatrix[i][j]);
                }
            }
        for (int k = 0; k < size; ++k)
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j) {
                    if (temp[i][k].getLength() && temp[k][j].getLength()) {
                        if (!temp[i][j].getLength()) {
                            temp[i][j] = temp[i][k] + temp[k][j];
                        } else if (temp[i][j].getLength() > temp[i][k].getLength() + temp[k][j].getLength()) {
                            temp[i][j] = temp[i][k] + temp[k][j];
                        }
                    }
                }
        return temp[destinationNameToIndex[source]][destinationNameToIndex[target]];
    }
}

std::vector<destination> Map::getAllDestination() const {
    return destinationInfo;
}

destination Map::queryDestination(std::string name) const {
    if (destinationNameToIndex.find(name) != destinationNameToIndex.end()) {
        return destinationInfo[destinationNameToIndex[name]];
    }
    throw 1;
}
