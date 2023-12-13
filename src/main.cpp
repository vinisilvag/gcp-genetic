#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

#include "genetic.h"
#include "graph.h"

Graph* read_input(std::string path)
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
            if (vertices || edges) {
              std::cout << "Failed reading the input graph!"
                        << "\n";

              exit(1);
            }
            if (iss >> format >> vertices >> edges) {
              if (format != "edge") {
                std::cout << "Failed reading the input graph!"
                          << "\n";

                exit(1);
              }

              graph->set_number_of_nodes(vertices);
            }
            break;
          case 'e':
            if (iss >> u >> v) graph->add_edge(u - 1, v - 1);
            break;
          default:
            std::cout << "Failed reading the input graph!"
                      << "\n";

            exit(1);
        }
      }
    }

    file.close();
  }

  return graph;
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Graph path is required."
              << "\n";

    exit(1);
  }

  std::string path = argv[1];

  Graph* graph = read_input(path);

  Genetic* genetic = new Genetic(graph, 100, 100, 2, 0.01);

  int number_of_colors;
  std::vector<int> coloring;

  std::tie(number_of_colors, coloring) = genetic->run_genetic();

  std::cout << number_of_colors << "\n";

  for (int v : coloring) {
    std::cout << v << " ";
  }

  std::cout << "\n";

  return 0;
}