//
// Created by Sergiy Chepurnoy on 29.05.2020.
//

#include "ArcGraph.h"
#include <cassert>


ArcGraph::ArcGraph(int verticesAmount) {
    this->verticesAmount = verticesAmount;
}

ArcGraph::ArcGraph(const IGraph &graph) {
    verticesAmount = graph.VerticesCount();
    for (int from = 0; from < verticesAmount; from++) {
        for (int to:graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(isCorrectVertex(from) && isCorrectVertex(to));
    for (std::pair<int, int> edge: edgesList) {
        if (edge.first == from && edge.second == to) {
            return;
        }
    }
    edgesList.push_back({from,to});
}

int ArcGraph::VerticesCount() const {
    return verticesAmount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> res;
    for (std::pair<int, int> edge: edgesList) {
        if (edge.first == vertex) {
            res.push_back(edge.second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;
    for (std::pair<int, int> edge: edgesList) {
        if (edge.second == vertex) {
            res.push_back(edge.first);
        }
    }
    return res;
}

bool ArcGraph::isCorrectVertex(int vertex) const {
    return vertex >= 0 && vertex < verticesAmount;

}
