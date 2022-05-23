#include "Graph.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <stack>
#include <queue>
#include <stdlib.h>

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
    std::string label;
    ifstream input_file(filename);
    getline(input_file, line);
    for (char letter : line){
        if (letter == ','){
            std::string vertex = label;
            vertexes.push_back(vertex);
            std::vector<Edge> empty {};
            edges_dict.insert({vertex,empty});
            label = "";
        }
        else {
            label.push_back(letter);
        }
    }
    int index_origin = 0;
    int index_target = 0;
    while (getline(input_file, line)){
        index_target = -1;
        for (char letter : line){
            if (letter == ','){
                index_target++;
                if (!(label == "")){
                    double value = atof(label.c_str());
                    edges_dict[vertexes[index_origin]].push_back(Edge(vertexes[index_target],value));
                    label = "";
                }
            }
            else {
                label.push_back(letter);
            }
        }
        index_origin++;
    }
}

bool Graph::vertex_in_graph(const std::string& vertex){
    if (edges_dict.count(vertex) == 0){
        return false;
    }
    return true;
}

void Graph::add_edge(const std::string& origin,const std::string& target,const double& value){
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
        std::cout << "origin : " << pair.first << "\n";
        for (Edge edge : pair.second){
            edge.print();
        }
    }
    std::cout << "*****************************" << std::endl;
}

void Graph::explore(const std::string& vertex, std::set<std::string>& flagged){
    flagged.insert(vertex);
    std::cout << vertex << " -> ";
    for (Edge edge : edges_dict[vertex]){
        std::string target = edge.get_target();
        if (!flagged.contains(target)){
            explore(target,flagged);
        }
    }
}

void Graph::depth_first_search_recursif(){
    std::set<std::string> flagged;
    for (auto const &pair: edges_dict){
        if (!flagged.contains(pair.first)){
            explore(pair.first,flagged);
        }
    }
    std::cout << std::endl;
}

void Graph::depth_first_search_recursif(const std::string& origin){
    std::set<std::string> flagged;
    explore(origin,flagged);
    std::cout << std::endl;
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
        if (!flagged.contains(pair.first)){
            queue.push(pair.first);
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
        }
    }
    std::cout << std::endl;
}