#include <iostream>
#include <string>
using namespace std;

int result = 1;
string preOrder;
string postOrder;

/* postIndex is reverse */
void recursiveFindResult(int preStartIndex, int preEndIndex,
						 int postStartIndex, int postEndIndex) {
	/* endCondition */
	if (preEndIndex - preStartIndex == 1) {
		result *= 2;
		return;
	}
}