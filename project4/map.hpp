#ifndef MAP_HPP
#define MAP_HPP
#include "road.hpp"
#include "destination.hpp"
#include "path.hpp"
#include <map>
#include <vector>
#include <string>
class map {
    private:
        std::vector<std::vector<road> > adjaMatrix;
        std::map<std::string, int> destinationNameToIndex;
        vector<destination> destinationInfo;
        bool whetherSuccessInitialize;
    public:
        // read from file
        map(std::string destinationInfo, std::string roadInfo);
        bool checkWhetherSuccessInitialize() const;
        path getShortestPath(std::string begin, std::string end, bool canWalk, bool canDrive);
};
#endif
