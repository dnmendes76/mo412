#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include "grafo.h"
#include <vector>
#include <algorithm>

using namespace std;

#define INF 112345678

class Fluxo_Ford_Fulkerson{
public:
  Graph graph;
  Graph residual;
  int mf, f;
  vector<int>vis;
  vector<int>p;

  Fluxo_Ford_Fulkerson () {};
  Fluxo_Ford_Fulkerson(Graph graph);

  void augment(int v, int min_edge);
  void find_path(int u);
  Graph solve();
};

#endif

