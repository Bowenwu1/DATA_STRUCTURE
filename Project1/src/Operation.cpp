#include "Operation.h"

Operation::Operation(const Train & t_train, int t_from, int t_to):
		train(t_train), from(t_from), to(t_to) {}

int Operation::getFromNum() const { return from; }
void Operation::setFromNum(int n) { from = n; }

int Operation::getToNum() const { return to;  }
void Operation::setToNum(int n) { to = n;  }

Train Operation::getTrain() const { return train;  }
void Operation::setTrain(const Train & other) { train = other;  }
