#include "Graph.h"
#include <iostream>


int main(){
    std::string filename;
    std::cout << "enter a file name" << std::endl;
    std::cin >> filename;
    Graph graph;
    graph.init(filename);
    graph.print();
    graph.breadth_first_search();
}