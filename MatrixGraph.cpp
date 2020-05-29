//
// Created by Sergiy Chepurnoy on 29.05.2020.
//

#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int verticesAmount) {
    adjacencyMatrix.resize(verticesAmount);
    for (int i = 0; i < verticesAmount; ++i){
        adjacencyMatrix[i].resize(verticesAmount);
        for(int j=0; j<verticesAmount; j++){
            adjacencyMatrix[i][j]= false;
        }
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
    int verticesAmount = graph.VerticesCount();
    adjacencyMatrix.resize(verticesAmount);
    for (int i = 0; i < verticesAmount; ++i){
        adjacencyMatrix[i].resize(verticesAmount);
        for(int j=0; j<verticesAmount; j++){
            adjacencyMatrix[i][j]= false;
        }
    }
    for(int from=0; from<verticesAmount; from++){
        for(int to:graph.GetNextVertices(from)) {
            AddEdge(from, to);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(isCorrectVertex(from) && isCorrectVertex(to));
    adjacencyMatrix[from][to] = true;
}





int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    std::vector<int> res;
    for(int j=0; j<adjacencyMatrix.size(); j++) {
        if (adjacencyMatrix[vertex][j]) {
            res.push_back(j);
        }
    }
    return res;
}



std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(isCorrectVertex(vertex));
    std::vector<int> res;
    for(int i=0; i<adjacencyMatrix.size(); i++) {
        if (adjacencyMatrix[i][vertex]) {
            res.push_back(i);
        }
    }
    return res;}

bool MatrixGraph::isCorrectVertex(int vertex) const {
    return vertex >= 0 && vertex < adjacencyMatrix.size();
}
