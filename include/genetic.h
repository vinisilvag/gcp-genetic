#ifndef GENETIC_H
#define GENETIC_H

#include <tuple>
#include <vector>

#include "graph.h"

class Genetic
{
 private:
  Graph* graph;
  int generations;
  int population_size;
  int number_of_offsprings;
  double mutation_probability;

  std::vector<int> generate_individual(int n);
  void mutate(std::vector<int>& individual);
  std::tuple<std::vector<int>, std::vector<int>> select(
    int n, std::vector<int>& population
  );
  std::vector<int> crossover(int n, std::vector<int>& p1, std::vector<int>& p2);
  void replace(std::vector<int>& population);

 public:
  Genetic(
    Graph* graph, int generations = 150, int population_size = 100,
    int number_of_offsprings = 2, double mutation_probability = 0.01
  );
  std::tuple<int, std::vector<int>> run_genetic();
};

#endif