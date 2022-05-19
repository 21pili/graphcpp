#include <Edge.h>
#include <iostream>
#include <string>
#include <unordered_map>

class Graph{
    std::unordered_map<std::string, std::vector<Edge> > edges;

    public:

    Graph();
    void init(std::string filename);
    void print();
    void add_edge(std::string origin, std::string target, double value);
    bool vertex_in_graph(std::string vertex);
    void depth_first_search_recursif();
    void depth_first_search_recursif (const std::string& vertex_source);
    void depth_first_search_iteratif ();
    void depth_first_search_iteratif (const std::string& vertex_source) ;
    void breadth_first_search () const;
    void breadth_first_search (const std::string & first_vertex);

};

