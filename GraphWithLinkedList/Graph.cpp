#include "Graph.hpp"

Graph::Graph(int numberOfVertices) {
	count = numberOfVertices;
	if (count < 1)
		return;
	firstVertex = new Vertex(0);
	Vertex* temp = firstVertex;
	for (int i = 1; i < count; ++i) {
		temp->nextVertex = new Vertex(i);
		temp = temp->nextVertex;
	}
}

Graph::~Graph() {
	if (firstVertex)
		delete firstVertex;
}

Vertex* Graph::findVertex(int index) {
	Vertex* temp = firstVertex;
	while (temp) {
		if (temp->data == index)
			return temp;
		else
			temp = temp->nextVertex;
	}
	return NULL;
}

Edge* Graph::findEdge(Vertex* v, int target) {
	Edge* temp = v->firstEdge;
	while (temp) {
			if (temp->endPoint->data == target)
				return temp;
			else
				temp = temp->nextEdge;
	}
	return NULL;
}

void Graph::BFS(void(*handler)(int)) {
	bool* visited = new bool[count];
	std::queue<Vertex*> data;
	for (int i = 0; i < count; ++i)
		visited[i] = false;
	for (Vertex* temp = firstVertex; temp != NULL; temp = temp->nextVertex) {
		if (!visited[temp->data]) {
			data.push(temp);
			visited[temp->data] = true;
			while (!data.empty()) {
				for (Edge* i = data.front()->firstEdge; i != NULL; i = i->nextEdge) {
					if (!visited[i->endPoint->data])
						data.push(i->endPoint);
					visited[i->endPoint->data] = true;
				}
				handler(data.front()->data);
				visited[data.front()->data] = true;
				data.pop();
			}
		}
	}
	delete[] visited;
}

void Graph::DFS(void(*handler)(int)) {
	bool* visited = new bool[count];
	for (int i = 0; i < count; ++i)
		visited[i] = false;
	for (Vertex* temp = firstVertex; temp != NULL; temp = temp->nextVertex) {
			if (!visited[temp->data]) {
				travelWithDFS(temp, visited, handler);
			}
	}
	delete visited;
}

void Graph::travelWithDFS(Vertex* v, bool* visited, void(*handler)(int)) {
	handler(v->data);
	visited[v->data] = true;
	for (Edge* temp = v->firstEdge; temp != NULL; temp = temp->nextEdge) {
			if (!visited[temp->endPoint->data]) {
				travelWithDFS(temp->endPoint, visited, handler);
			}
	}
}

bool Graph::addEdge(int start, int end, int weight) {
	if (start < count && end < count) {
		Vertex* temp_start = findVertex(start);
		Edge* temp = findEdge(temp_start, end);
		if (!temp) {
			Edge* find = temp_start->firstEdge;
			if (find) {
				while (find->nextEdge) {
					find = find->nextEdge;
				}
				find->nextEdge = new Edge(findVertex(end));
				return true;
			}
			else {
				temp_start->firstEdge = new Edge(findVertex(end));
				return true;
			}
		}
	}
	return false;
}