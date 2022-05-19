#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

Graph::Graph(std::string filename):
    std::tuple<std::unordered_map<std::string, std::vector <Edge> >, int, int> graph_attributes = read(filename);
    vertex_number(std::get<1>(graph_attributes)),
    edge_number(std::get<2>(graph_attributes)),
    edges(std::get<0>(graph_attributes))
{};

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
