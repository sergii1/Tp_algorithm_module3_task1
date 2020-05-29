//
// Created by Sergiy Chepurnoy on 28.05.2020.
//

#include "ListGraph.h"
#include <cassert>

void ListGraph::AddEdge(int from, int to) {
    assert(isCorrectVertex(from) && isCorrectVertex(to));
    //проверяем, есть ли уже такое ребро
    for (int vertex:adjacencyNextList[from]) {
        if (vertex == to)
            return;
    }
    adjacencyNextList[from].push_back(to);
    adjacencyPrevList[to].push_back(from);
}

int ListGraph::VerticesCount() const {
    return adjacencyNextList.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    return adjacencyNextList[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    std::vector<int> res;
    return adjacencyPrevList[vertex];
}

ListGraph::ListGraph(int verticesAmount) {
    adjacencyPrevList.resize(verticesAmount);
    adjacencyNextList.resize(verticesAmount);
}

ListGraph::ListGraph(const IGraph &graph) {
    int verticesAmount = graph.VerticesCount();
    adjacencyPrevList.resize(verticesAmount);
    adjacencyNextList.resize(verticesAmount);
    for(int from=0; from<verticesAmount; from++){
        for(int to:graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

bool ListGraph::isCorrectVertex(int vertex) const {
    return vertex>=0 && vertex<adjacencyNextList.size();
}