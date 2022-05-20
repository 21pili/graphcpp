#include "Graph.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <fstream>
#include <iterator>


int main(){
    std::string filename;
    std::cout << "enter a file name" << std::endl;
    std::cin >> filename;
    Graph graph;
    graph.init(filename);
    int number_vertexes = graph.get_dict().size();
    std::cout << "Le graphe est composé de " << number_vertexes << " sommets" << std::endl;
}