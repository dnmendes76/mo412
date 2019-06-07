#ifndef SAVE_H
#define SAVE_H

#include "grafo.h"

class Save{
public:
  Graph graph;

  Save () {};
  Save(Graph graph);

  void save_soluction(string path_in, string path_out);
};

#endif
