#ifndef PRIM_H
#define PRIM_H

#include "soluction.h"
#include <limits>

using namespace std;

class Par{
 public:
  int vertice;
  double peso;

  Par() {}

  Par(int v, double p) { vertice = v; peso = p; }
};

class MST_Prim{
	Soluction obter_soluction();
public:

	Graph graph;
	vector<Par> parent;

	MST_Prim(Graph graph);
    Soluction solve_heap_vector(int root);
	Soluction solve_heap_binary(int root);
	Soluction solve_heap_fibonacci_use_insert(int root);
	Soluction solve_heap_fibonacci_use_decrease(int root);
};

#endif
