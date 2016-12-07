#include "road.hpp"

road::road() {
    whetherThisRoadExist = false;
    availableForWalk = false;
    availableForCar = false;
    length = -1;
}

road::road(std::string s, std::string t, int l, bool _availableForWalk, bool _availableForCar):
    source(s), target(t), length(l),
    availableForWalk(_availableForWalk), availableForCar(_availableForCar) {}

int road::getLength() const { return length; }

bool road::canWalk() const { return availableForWalk; }
bool road::canDriveCar() const { return availableForCar; }

std::string road::getSource() const { return source; }
std::string road::getTarget() const { return target; }
