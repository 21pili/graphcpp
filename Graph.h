#include "Edge.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

class Graph{
    std::unordered_map<std::string, std::vector<Edge> > edges_dict;

    private:

    void explore(const std::string& vertex, std::set<std::string>& flagged);
    bool vertex_in_graph(const std::string& vertex);

    public:

    Graph();
    void init(std::string filename);
    void print();
    void add_edge(
        const std::string& origin, 
        const std::string& target, 
        const double& value);
    void depth_first_search_recursif();
    void depth_first_search_recursif (const std::string& vertex_source);
    void depth_first_search_iteratif ();
    void depth_first_search_iteratif (const std::string& vertex_source) ;
    void breadth_first_search ();
    void breadth_first_search (const std::string& first_vertex);
};

