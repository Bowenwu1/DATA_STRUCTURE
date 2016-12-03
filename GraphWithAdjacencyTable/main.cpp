#include <iostream>
#include "Digraph.hpp"
using namespace std;

void addEdge(Digraph& data);
void printHelpInformation();
void printElement(int a);

int main() {
	bool whetherContinue = true;
	cout << "please enter the graph size:";
	int size;
	cin >> size;
	Digraph test(size);
	printHelpInformation();
	while (whetherContinue) {
		char operation;
		cout << "$~";
		cin >> operation;
		switch(operation) {
			case 'a':
				addEdge(test);
				break;
			case 'b':
				test.BFS(printElement);
				cout << endl;
				break;
			case 'd':
				test.DFS(printElement);
				cout << endl;
				break;
			case 'q':
				whetherContinue = false;
				break;
			default:
				printHelpInformation();
				break;
		}
	}
}

void addEdge(Digraph& a) {
	cout << "Please enter startIndex endIndex weight" << endl;
	int start, end, weight;
	cin >> start >> end >> weight;
	if (a.addEdge(start, end, weight)) {
		cout << "success!" << endl;
	} else {
		cout << "fail! illegal input" << endl;
	}
}

void printHelpInformation() {
	cout << "q   --quit" << endl
		<< "a   --addEdge" << endl
		<< "b   --BFS" << endl
		<< "d   --DFS" << endl;
}

void printElement(int a) {
	cout << a << " ";
}