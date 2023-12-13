#include "graph.h"

Graph::Graph() {}

Graph::Graph(int number_of_nodes)
{
  this->n = number_of_nodes;
  this->adj_list.resize(n);
}

void Graph::set_number_of_nodes(int n)
{
  this->n = n;
  this->adj_list.resize(n);
}

int Graph::number_of_nodes() { return this->n; }

void Graph::add_edge(int u, int v)
{
  this->adj_list[u].push_back(v);
  this->adj_list[v].push_back(u);
}

std::vector<int> Graph::neighborhood(int u) { return this->adj_list[u]; }