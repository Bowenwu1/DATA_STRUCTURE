/* Created by BowenWu No.15331310
* Contact me at wubw6@mail2.sysu.edu.cn
* Code style requirement:
* 1, good looking
* 2, comment should be more than 30 percent;
*/
#ifndef TRAIN_HPP
#define TRAIN_HPP

class Train {
private:
	int number;
public:
	/* Default contructor forbidden */
	Train() = delete;

	/* contructor
	* @param n the number of train
	*/
	Train(int n);

	int getNum() const;
	void setNum(int n);

	bool operator>(const Train &);
	bool operator<(const Train &);

	bool operator==(const Train&);
	
	bool operator<=(const Train&);
	bool operator>=(const Train&);
};
#endif