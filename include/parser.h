#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "graph.h"

class Parser
{
 public:
  Parser();
  Graph* read_instance(std::string path);
};

#endif