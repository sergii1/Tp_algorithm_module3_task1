//
// Created by Sergiy Chepurnoy on 28.05.2020.
//

#ifndef MOD3_TASK1_IGRAPH_H
#define MOD3_TASK1_IGRAPH_H

#include <vector>
struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif //MOD3_TASK1_IGRAPH_H
