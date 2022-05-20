#include "Graph.h"
#include <vector>
#include <fstream>
#include <iterator>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

std::unordered_map<std::string, std::vector<Edge> > empty_dictionary;

Graph::Graph():
    edges_dict(empty_dictionary)
{};

void Graph::init(std::string filename){
    std::vector<std::string> vertexes;
    std::string line;
    ifstream input_file(filename);
    getline(input_file, line);
    for (char letter : line){
        std::string vertex = std::string(1,letter);
        vertexes.push_back(vertex);
    }
    int index_origin = 0;
    int index_target = 0;
    while (getline(input_file, line)){
        index_target = 0;
        for (char c : line){
            if (c == ','){
                index_target++;
            }
            else {
                int value = c - 48;
                edges_dict[vertexes[index_origin]].push_back(Edge(vertexes[index_target],value));
            }
        }
        index_origin++;
    }
}

bool Graph::vertex_in_graph(std::string vertex){
    if (edges_dict.count(vertex) == 0){
        return false;
    }
    return true;
}

void Graph::add_edge(std::string origin, std::string target, double value){
    if (!vertex_in_graph(origin)){
        edges_dict[origin].push_back(Edge(target, value));
    }
}

void Graph::print(){
    for (auto const &pair: edges_dict) {
        std::cout << "origin: " << pair.first;
        std::cout << std::endl;
        for (Edge edge : pair.second){
            edge.print();
            std::cout << std::endl;
        }
    }
}

std::unordered_map<std::string, std::vector<Edge> > Graph::get_dict(){
    return edges_dict;
}
