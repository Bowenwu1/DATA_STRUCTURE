/*Created by 15331310BowenWu
 *DS PROJECT ONE
 */


#include "TrainManager.hpp"
#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> data;
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        data.push_back(temp);
    }
    std::cout << TrainManager::getInstruction(data);
    return 0;
}