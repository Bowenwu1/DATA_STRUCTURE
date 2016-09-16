// Created By BowenWu
// DS PROJECT ONE
// TRAIN_MANAGER
// 2016.09.10


#ifndef TRAIN_MANAGER_HPP
#define TRAIN_MANAGER_HPP
#include "Train.hpp"
#include "Operation.hpp"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

class TrainManager {
  public:
    static std::string getInstruction(std::vector<int> data);
  private:
    /**
     *@param trainNum the No of the train
     *@param from where this train come from
     * 0 stand for local
     *@param to move this train to where
     * 0 stand for target
     */
    static std::string InstructionToString(int trainNum, int from, int to);

    /**
     *@param track_num how many track are needed
     */
    static std::string InstructionToString(int track_num);
};

#endif