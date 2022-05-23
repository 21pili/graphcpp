#include "Edge.h"

Edge::Edge(std::string target, double value):
    target(target),
    value(value)
{}

void Edge::print(){
    std::cout << "--" << value << "--> " << target << "\n";
}

std::string Edge::get_target(){
    return target;
}

double Edge::get_value(){
    return value;
}