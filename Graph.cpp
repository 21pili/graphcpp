#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <fstream>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

std::unordered_map<std::string, std::vector<Edge> > empty_dictionary;

Graph::Graph():
    edges(empty_dictionary)
{};

void Graph::init(std::string filename){
    std::vector<std::string> vertexes;
    std::string line;
    ifstream input_file(filename);
    getline(input_file, line);
    for (char c : line){
        vertexes.push_back(c);
    }
    int index_origin = 0;
    int index_target = 0;
    while (getline(input_file, line)){
        for (char c : line){
            if (c == ','){
                index_target++;
            }
            else {
                double value = c;
                edges[vertexes[index_origin]] = Edge(vertexes[index_target],value);
            }
        }
    }
}

bool Graph::vertex_in_graph(std::string vertex){
    if (edges.count(vertex) == 0){
        return false;
    }
    return true;
}

void Graph::add_edge(std::string origin, std::string target, double value){
    if (!vertex_in_graph(origin)){
        edges[origin] = Edge(target, value);
    }
}
// on définit ici la fonction read.
