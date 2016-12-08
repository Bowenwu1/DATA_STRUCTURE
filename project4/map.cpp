#include "map.hpp"

map::map(std::string dPath, std::string rPath) {
    std::fstream fs(dPath);
    int id = 0;
    while (!fs.eof()) {
        std::string name, description;
        destination temp(name, description);
        destinationNameToIndex[temp] = id++;
    }
    fs.close();
    fs.open(rPath);
    // input road information
    while (!fs.eof()) {
        std::string source, target, length;
        bool whetherWalk, whetherDrive;
    }

}