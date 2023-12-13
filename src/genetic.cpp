#include "genetic.h"

Genetic::Genetic(
  Graph* graph, int generations, int population_size, int number_of_offsprings,
  double mutation_probability
)
{
  this->graph = graph;
  this->generations = generations;
  this->population_size = population_size;
  this->number_of_offsprings = number_of_offsprings;
  this->mutation_probability = mutation_probability;
}

std::vector<int> Genetic::generate_individual(int n)
{
  std::vector<int> individual(n);

  return individual;
}

void Genetic::mutate(std::vector<int>& individual) {}

std::tuple<std::vector<int>, std::vector<int>> Genetic::select(
  int n, std::vector<int>& population
)
{
  std::vector<int> p1(n), p2(n);

  return {p1, p2};
}

std::vector<int> Genetic::crossover(
  int n, std::vector<int>& p1, std::vector<int>& p2
)
{
  std::vector<int> offspring(n);

  return offspring;
}

void Genetic::replace(std::vector<int>& population) {}

std::tuple<int, std::vector<int>> Genetic::run_genetic()
{
  int n = this->graph->number_of_nodes();
  std::vector<int> best(n);
  std::vector<std::vector<int>> population;

  for (int i = 0; i < this->population_size; i++) {
    std::vector<int> individual = generate_individual(n);
    population.push_back(individual);
  }

  for (int i = 0; i < generations; i++) {
    // do stuff
  }

  return {0, best};
}