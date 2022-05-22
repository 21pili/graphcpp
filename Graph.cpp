#include "Graph.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <stack>
#include <queue>


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
    if (vertex_in_graph(origin)){
        edges_dict[origin].push_back(Edge(target, value));
    }
    else {
        std::vector<Edge> edge {Edge(target,value)};
        edges_dict.insert({origin,edge});
    }
    if(!vertex_in_graph(target)){
        std::vector<Edge> empty {};
        edges_dict.insert({target,empty});
    }
}

void Graph::print(){
    std::cout << "*****************************" << std::endl;
    for (auto const &pair: edges_dict) {
        std::cout << "origin: " << pair.first << std::endl;
        std::cout << std::endl;
        for (Edge edge : pair.second){
            edge.print();
            std::cout << std::endl;
        }
    }
}

std::unordered_map<std::string, std::vector<Edge> > Graph::dict(){
    return edges_dict;
}

void Graph::explore(std::string vertex, std::set<std::string>& flagged){
    flagged.insert(vertex);
    std::cout << vertex;
    for (Edge edge : edges_dict[vertex]){
        std::string target = edge.get_target();
        if (!flagged.contains(target)){
            std::cout << " -> ";
            explore(target,flagged);
        }
    std::cout << std::endl;
    }
}

void Graph::depth_first_search_recursif(){
    std::cout << "*******Parcours en profondeur récursif*******" << std::endl;
    std::set<std::string> flagged;
    for (auto const &pair: edges_dict){
        if (!flagged.contains(pair.first)){
            explore(pair.first,flagged);
        }
    }
}

void Graph::depth_first_search_recursif(const std::string& origin){
    std::cout << "*******Parcours en profondeur récursif en partant de " << origin <<  "*******" << std::endl;
    std::set<std::string> flagged;
    explore(origin,flagged);
}

void Graph::depth_first_search_iteratif(const std::string& origin){
    std::stack<std::string> stack;
    std::set<std::string> flagged;
    stack.push(origin);
    while (!stack.empty()){
        std::string vertex = stack.top();
        stack.pop();
        if (!flagged.contains(vertex)){
            flagged.insert(vertex);
            std::cout << vertex << " -> ";
            for (Edge edge : edges_dict[vertex]){
                stack.push(edge.get_target());
            }
        }
    }
    std::cout << std::endl;
}

void Graph::depth_first_search_iteratif(){
    std::stack<std::string> stack;
    std::set<std::string> flagged;
    for (auto const &pair: edges_dict){
        stack.push(pair.first);
    }
    while (!stack.empty()){
        std::string vertex = stack.top();
        stack.pop();
        if (!flagged.contains(vertex)){
            flagged.insert(vertex);
            std::cout << vertex << " -> ";
            for (Edge edge : edges_dict[vertex]){
                stack.push(edge.get_target());
            }
        }
    }
    std::cout << std::endl;
}

void Graph::breadth_first_search(const std::string& origin){
    std::queue<std::string> queue;
    std::set<std::string> flagged;
    queue.push(origin);
    while (!queue.empty()){
        std::string vertex = queue.front();
        queue.pop();
        if (!flagged.contains(vertex)){
            flagged.insert(vertex);
            std::cout << vertex << " -> ";
            for (Edge edge : edges_dict[vertex]){
                queue.push(edge.get_target());
            }
        }
    }
    std::cout << std::endl;
}

void Graph::breadth_first_search(){
    std::queue<std::string> queue;
    std::set<std::string> flagged;
    for (auto const &pair: edges_dict){
        queue.push(pair.first);
    }
    while (!queue.empty()){
        std::string vertex = queue.front();
        queue.pop();
        if (!flagged.contains(vertex)){
            flagged.insert(vertex);
            std::cout << vertex << " -> ";
            for (Edge edge : edges_dict[vertex]){
                queue.push(edge.get_target());
            }
        }
    }
    std::cout << std::endl;
}