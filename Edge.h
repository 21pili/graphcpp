#include <iostream>
#include <string>

class Edge{
    std::string target;
    double value;

    public:

    Edge(std::string target, double value);
    void print();
    std::string get_target();
    double get_value();
};