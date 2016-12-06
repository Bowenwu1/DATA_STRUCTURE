#ifndef PATH_HPP
#define PATH_HPP
#include <deque>
#include <string>
#include <vector>
#include "destination.hpp"
#include "road.hpp"
class path {
    private:
        int totalLength;
        std::string begin, end;
        std::deque<road> data;
    public:
        path();
        // remember modify begin, end, totalLength
        void appendLastRoad(const road &);
        void appendFirstRoad(const road &);
        // only can delete last road or first road
        void deleteLastRoad();
        void deleteFirstRoad();

        std::string getBegin() const;
        std::string getEnd() const;\

        std::vector<string> getRoadName() const;
        std::vector<string> getDestinationName() const;

        /* if you have any extra request API
         * just contact me
         */
};
#endif