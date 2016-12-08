#include "map.hpp"

map::map(std::string dPath, std::string rPath) {
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
        if (destinationNameToIndex.find(temp) == destinationNameToIndex.end())
            destinationNameToIndex[temp] = id++;
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
    while (!fs.eof()) {
        std::string source, target, length;
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

bool map::checkWhetherSuccessInitialize() const {
    return whetherSuccessInitialize;
}

path map::getShortestPath(std::string begin, std::string end, bool canWalk, bool canDriveCar) const {
    if (whetherSuccessInitialize) {
        // first use BFS let the program run
        
    }
}