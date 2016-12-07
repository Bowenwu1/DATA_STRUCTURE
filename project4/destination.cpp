#include "destination.hpp"

destination::destination(std::string n, std::string d):name(n), description(d) {}

void destination::setName(std::string newName) {
    name = newName;
}
std::string destination::getName() const { return name; }

void destination::setLocation(std::string l) { location = l; }
std::string destination::getLocation() const { return location; }

void destination::setDescription(std::string d) { description = d; }
std::string destination::getDescription() const { return description; }
