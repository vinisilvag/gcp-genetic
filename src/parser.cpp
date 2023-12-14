#include "parser.h"

#include <fstream>
#include <istream>
#include <sstream>

Parser::Parser() {}

Graph* Parser::read_instance(std::string path)
{
  int vertices = 0, edges = 0;
  std::ifstream file(path);

  Graph* graph = new Graph();

  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      std::istringstream iss(line);
      char ch;

      if (iss >> ch) {
        int u, v;
        std::string format;

        switch (ch) {
          case 'c':
            break;
          case 'p':
            if (vertices || edges) exit(1);
            if (iss >> format >> vertices >> edges) {
              if (format != "edge") exit(1);
              graph->set_number_of_nodes(vertices);
            }
            break;
          case 'e':
            if (iss >> u >> v) graph->add_edge(u - 1, v - 1);
            break;
          default:
            exit(1);
        }
      }
    }

    file.close();
  }

  return graph;
}
