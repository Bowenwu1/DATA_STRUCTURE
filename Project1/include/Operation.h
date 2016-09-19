/* Created by BowenWu No.15331310
* Contact me at wubw6@mail2.sysu.edu.cn
* Code style requirement:
* 1, good looking
* 2, comment should be more than 30 percent;
*/
#ifndef OPERATION_HPP
#define OPERATION_HPP
#include "Train.h"

class Operation {
private:
	Train train;
	/* from stand for where the train come from
	* 0 stand for origin
	* ask me for here
	*/
	int from;
	/* to stand for where the train are coming to
	* 0 stand for target
	* ask me for here
	*/
	int to;
public:
	/* default constructor forbidden */
	Operation() = delete;

	Operation(const Train & train, int from, int to);

	int getFromNum() const;
	void setFromNum(int n);

	int getToNum() const;
	void setToNum(int n);

	Train getTrain() const;
	void setTrain(const Train &);
};
#endif