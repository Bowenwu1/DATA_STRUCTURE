// class Digraph with the implementation of adjacency table
// Created by Bowenwu

#define MAX_SIZE 100
#include <queue>
class Digraph {
private:
	// number of vertices
	int count;
	// -1 stand for no edge between two vertex
	int adjacency[MAX_SIZE][MAX_SIZE];
	void travelWithDFS(int v, bool* visited, void(*handler)(int));
public:
	Digraph(int numberOfVertices);
	~Digraph();

	bool addEdge(int start, int end, int weight);

	void DFS(void(*handler)(int));
	void BFS(void(*handler)(int));
};