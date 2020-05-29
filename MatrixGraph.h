//
// Created by Sergiy Chepurnoy on 29.05.2020.
//

#ifndef MOD3_TASK1_MATRIXGRAPH_H
#define MOD3_TASK1_MATRIXGRAPH_H

#include "IGraph.h"
#include "iostream"

class MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(int verticesAmount);
    explicit MatrixGraph(const IGraph& graph);
    void AddEdge(int from, int to) override ;

    int VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void printNexVertices(){
        std::cout<<"printNexVertices"<<std::endl;

        for(int i=0; i< adjacencyMatrix.size(); ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetNextVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }

    void printPrevVertices(){
        std::cout<<"printPrevVertices"<<std::endl;
        for(int i=0; i< adjacencyMatrix.size(); ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetPrevVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }
private:
    bool isCorrectVertex(int vertex) const;
    std::vector<std::vector<bool>> adjacencyMatrix;
};


#endif //MOD3_TASK1_MATRIXGRAPH_H
