//
// Created by Sergiy Chepurnoy on 28.05.2020.
//

#ifndef MOD3_TASK1_LISTGRAPH_H
#define MOD3_TASK1_LISTGRAPH_H

#include "IGraph.h"
#include <vector>
#include <list>
#include <iostream>

class ListGraph:public IGraph {
public:
    explicit ListGraph(int verticesAmount);
    explicit ListGraph(const IGraph& graph);
    void AddEdge(int from, int to) override ;

    int VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void printNexVertices(){
        std::cout<<"printNexVertices"<<std::endl;

        for(int i=0; i< adjacencyNextList.size(); ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetNextVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }

    void printPrevVertices(){
        std::cout<<"printPrevVertices"<<std::endl;
        for(int i=0; i< adjacencyNextList.size(); ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetPrevVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }
private:
    bool isCorrectVertex(int vertex) const;
    std::vector<std::vector<int>> adjacencyNextList;
    std::vector<std::vector<int>> adjacencyPrevList;
};


#endif //MOD3_TASK1_LISTGRAPH_H
