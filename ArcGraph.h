//
// Created by Sergiy Chepurnoy on 29.05.2020.
//

#ifndef MOD3_TASK1_ARCGRAPH_H
#define MOD3_TASK1_ARCGRAPH_H

#include "IGraph.h"
#include "iostream"

class ArcGraph: public IGraph {
public:
    explicit ArcGraph(int verticesAmount);
    explicit ArcGraph(const IGraph& graph);
    void AddEdge(int from, int to) override ;

    int VerticesCount() const  override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void printNexVertices(){
        std::cout<<"printNexVertices"<<std::endl;

        for(int i=0; i< verticesAmount; ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetNextVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }

    void printPrevVertices(){
        std::cout<<"printPrevVertices"<<std::endl;
        for(int i=0; i< verticesAmount; ++i){
            std::cout<<"vertex"<< i ;
            for(int v:GetPrevVertices(i)){
                std::cout<<" "<<v;
            }
            std::cout<<std::endl;
        }
    }
private:
    int verticesAmount;
    bool isCorrectVertex(int vertex) const;
    std::vector<std::pair<int , int>> edgesList;
};


#endif //MOD3_TASK1_ARCGRAPH_H
