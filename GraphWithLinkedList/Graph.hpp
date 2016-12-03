// class Graph with the implementation of adjacency table
// Created by Bowenwu

#define MAX_SIZE 100
#include <queue>
class Edge;
class Vertex {
public:
	int data;
	Edge *firstEdge;
	Vertex *nextVertex;
	Vertex(int d):data(d) {
		nextVertex = NULL;
		firstEdge = NULL;
	}
	~Vertex() {
		if (firstEdge)
			delete firstEdge;
		if (nextVertex)
			delete nextVertex;
	}
};

class Edge {
public:
	Vertex *endPoint;
	Edge *nextEdge;
	Edge(Vertex* end, Edge* next = NULL):endPoint(end), nextEdge(next) {}
	~Edge() {
		if (nextEdge)
			delete nextEdge;
	}
};

class Graph {
private:
	int count;
	Vertex *firstVertex;
	void travelWithDFS(Vertex* v, bool* visited, void(*handler)(int));
	Vertex* findVertex(int index);
	Edge* findEdge(Vertex* v, int target);
public:
	Graph(int numberOfVertices);
	~Graph();

	bool addEdge(int start, int end, int weight);

	void DFS(void(*handler)(int));
	void BFS(void(*handler)(int));
};