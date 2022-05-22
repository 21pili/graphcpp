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
    graph.depth_first_search_recursif("e");
}