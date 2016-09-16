// Created By BowenWu
// DS PROJECT ONE
/* Created by BowenWu No.15331310
 * Contact me at wubw6@mail2.sysu.edu.cn
 * Code style requirement:
 * 1, good looking
 * 2, comment should be more than 30 percent;
 */
#ifndef TRAIN_INSTRUCTION_HPP
#define TRAIN_INSTRUCTION_HPP
#include "Train.hpp"
#include "Operation.hpp"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

class TrainInstruction {
  private:
    struct TI {
      std::vector<Train> data;
      int TotalTruck;
    };
  public:

    /* Before using this function
     * you should make sure
     * that you have check data format
     * by using bool verify()
     */
    static TI getInstruction(std::vector<Train>);

    /* check whether train data are legal */
    static bool verify(const std::vector<Train> &);
};

#endif