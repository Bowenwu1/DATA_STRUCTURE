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
#include "Train.h"
#include "Operation.h"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>

class TrainInstruction {
private:
	struct TI {
		std::vector<Operation> data;
		int TotalTruck;
	};
	/* storage the condition */
	static std::vector<std::stack<Train>> truck;
	static std::deque<Train> origin;
	static std::deque<Train> target;
	static int TotalTrain;
	static TI result;
	/* Recursion find the best solution 
	 * 1, least truck
	 * 2, least stops
	 */
	static void find_result(TI &);
public:

	/* Before using this function
	* you should make sure
	* that you have check data format
	* by using bool verify()
	*/
	static TI getInstruction(const std::vector<Train>&);

	/* check whether train data are legal */
	static bool verify(std::vector<Train>);
};

#endif
