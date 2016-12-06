/* Created by Bowenwu in 20161207
 * class Road
 * storage source and target, length, whether available
 * for car and foot
 */
#ifndef ROAD_HPP
#define ROAD_HPP
#include <string>
class road {
    private:
        std::string source, target;
        int length;
        bool availableForWalk;
        bool availableForCar;
        bool whetherThisRoadExist;
    public:
        // default constructor make whetherThisRoadExist false
        road();
        // make whetherThisRoadExist true
        road(str::string source, std::string target, int length, bool availableForWalk, bool availableForCar);

        int getLength() const;

        bool canWalk() const;
        bool canDriveCar() const;
};
#endif