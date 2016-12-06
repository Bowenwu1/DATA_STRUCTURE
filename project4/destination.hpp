/* Created by Bowenwu in 20161206
 * storage each destination data
 */
#ifndef DESTINATION_HPP
#define DESTINATION_HPP
#include <string>
#include <vector>
class destination {
    private:
        std::string name;
        std::string location;
        std::string description;
    public:
        destination() = delete;
        destination(std::string n, std::string d);
        
        void setName(std::string name);
        std::string getName() const;

        void setLocation(std::string location);
        std::string getLocation() const;

        void setDescription(std::string description);
        std::string getDescription() const;
};
#endif
