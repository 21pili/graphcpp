#include "Edge.h"

Edge::Edge(std::string target, double value):
    target(target),
    value(value)
{}

void Edge::print(){
    std::cout << "--" << value << "-->" << target << std::endl;
}
