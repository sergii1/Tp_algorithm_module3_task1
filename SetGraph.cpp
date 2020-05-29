//
// Created by Sergiy Chepurnoy on 29.05.2020.
//

#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int verticesAmount) {
    adjacencyList.resize(verticesAmount);
}

SetGraph::SetGraph(const IGraph &graph) {
    int verticesAmount = graph.VerticesCount();
    adjacencyList.resize(verticesAmount);
    for(int from=0; from<verticesAmount; from++){
        for(int to:graph.GetNextVertices(from)) {
            this->AddEdge(from, to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(isCorrectVertex(from) && isCorrectVertex(to));
    adjacencyList[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacencyList.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    std::vector<int> res;
    for (int v:adjacencyList[vertex]) {
        res.push_back(v);
    }
    return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    std::vector<int> res;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if(adjacencyList[i].find(vertex)!=adjacencyList[i].end())
            res.push_back(i);
    }
    return res;
}

bool SetGraph::isCorrectVertex(int vertex) const {
    return vertex>=0 && vertex<adjacencyList.size();
}
