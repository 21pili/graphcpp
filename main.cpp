#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>

int main(){
    std::tuple<int, double, bool> tup {1,42.0,false};
    int arg1  = std::get<0>(tup);
    std::cout << arg1 << std::endl;
}

