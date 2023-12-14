#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "genetic.h"
#include "graph.h"
#include "parser.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << "Graph path is required."
              << "\n";

    exit(1);
  }

  std::string path = argv[1];

  Parser* parser = new Parser();
  Graph* graph = parser->read_instance(path);

  Genetic* genetic = new Genetic(graph);

  auto start = std::chrono::steady_clock::now();

  // int, std::vector<int>
  auto [number_of_colors, coloring] = genetic->run_genetic();

  int duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::steady_clock::now() - start
  )
                   .count();

  std::cout << "Colors: " << number_of_colors << "\n";

  std::cout << "Coloring: "
            << "\n";
  for (int v : coloring) {
    std::cout << v << " ";
  }

  std::cout << "\n"
            << "Duration: " << duration << "\n";

  return 0;
}