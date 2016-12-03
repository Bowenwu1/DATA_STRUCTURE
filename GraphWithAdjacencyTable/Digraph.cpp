#include "Digraph.hpp"

Digraph::Digraph(int numberOfVertices) {
	count = numberOfVertices;
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			adjacency[i][j] = -1;
}

Digraph::~Digraph() {}

// index of verticex start from zero
bool Digraph::addEdge(int start, int end, int weight) {
	if (start < count && end < count) {
		adjacency[start][end] = weight;
		adjacency[end][start] = weight;
		return true;
	} else {
		return false;
	}
}

void Digraph::DFS(void(*handler)(int)) {
	bool* visited = new bool[count];
	for (int i = 0; i < count; ++i)
		visited[i] = false;
	for (int start = 0; start < count; ++start) {
		if (!visited[start])
			this->travelWithDFS(start, visited, handler);
	}
	delete[] visited;
}

void Digraph::BFS(void(*handler)(int)) {
	bool* visited = new bool[count];
	for (int i = 0; i < count; ++i)
		visited[i] = false;
	std::queue<int> data;
	data.push(0);
	visited[0] = true;
	while(!data.empty()) {
		// push the adjacent vertices
		for (int i = 0; i < count; ++i) {
			if (adjacency[data.front()][i] != -1 && !visited[i]) {
				data.push(i);
				visited[i] = true;
			}
		}
		handler(data.front());
		data.pop();
	}
	delete[] visited;
}

void Digraph::travelWithDFS(int v, bool* visited, void(*handler)(int)) {
	handler(v);
	visited[v] = true;
	for (int i = 0; i < count; ++i) {
		if (adjacency[i][v] != -1 && !visited[i]) {
			this->travelWithDFS(i, visited, handler);
		}
	}
}