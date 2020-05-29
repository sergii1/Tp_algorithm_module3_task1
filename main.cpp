#include <iostream>
#include <vector>
#include <list>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
using  namespace std;
int main() {

    cout<<"ARC GR"<<endl<<endl;
    ArcGraph gr1(5);
    gr1.AddEdge(0,3);
    gr1.AddEdge(3,0);
    gr1.AddEdge(0,4);
    gr1.AddEdge(4,2);
    gr1.AddEdge(1,2);
    gr1.printNexVertices();
    gr1.printPrevVertices();

    cout<<"LIST GR"<<endl<<endl;
    ListGraph gr(gr1);
//    gr.AddEdge(0,3);
//    gr.AddEdge(3,0);
//    gr.AddEdge(0,4);
//    gr.AddEdge(4,2);
//    gr.AddEdge(1,2);
    gr.printNexVertices();
    gr.printPrevVertices();


    return 0;
}
