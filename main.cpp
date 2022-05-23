#include <iostream>
#include "Graph.h"

int main () {
  std::cout << "entrez un nom de fichier: ";
  std::string filename;
  std::cin >> filename;
  Graph graph;
  graph.init(filename);
  std::cout << "graph.print()\n";
  graph.print();
  std::cout << "graph.depth_first_search_recursif()\n";
  graph.depth_first_search_recursif();
  std::cout << "graph.depth_first_search_iteratif()\n";
  graph.depth_first_search_iteratif();
  std::cout << "graph.breadth_first_search()\n";
  graph.breadth_first_search();
  std::cout << "Entrez un nom de sommet: ";
  std::string name;
  std::cin >> name;
  std::cout << "graph.depth_first_search_recursif(" << name << ")\n";
  graph.depth_first_search_recursif(name);
  std::cout << "graph.depth_first_search_iteratif(" << name << ")\n";
  graph.depth_first_search_iteratif(name);
  std::cout << "graph.breadth_first_search(" << name << ")\n";
  graph.breadth_first_search(name);
  Graph g;
  g.add_edge("toto", "tutu", 2.6);
  g.add_edge("tutu", "tata", 3.5);
  g.add_edge("tata", "toto", 17.56);
  g.print();
  return EXIT_SUCCESS;
}