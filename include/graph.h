#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
 private:
  int n;
  std::vector<std::vector<int>> adj_list;

 public:
  Graph();
  Graph(int n);
  void set_number_of_nodes(int n);
  int number_of_nodes();
  void add_edge(int u, int v);
  std::vector<int> neighborhood(int u);
};

#endif