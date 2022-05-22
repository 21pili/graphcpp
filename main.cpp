#include "Graph.h"
#include <iostream>


int main(){
    std::string filename;
    std::cout << "enter a file name" << std::endl;
    std::cin >> filename;
    Graph graph;
    graph.init(filename);
    int number_vertexes = graph.dict().size();
    graph.print();
    graph.add_edge("a","b",67);
    graph.print();
    graph.add_edge("toto","b",89);
    graph.print();
    graph.add_edge("c","oui",6);
    graph.print();
}