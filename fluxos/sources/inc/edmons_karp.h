#ifndef EDMONS_KARP_H
#define EDMONS_KARP_H

#include "grafo.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 112345678

class Fluxo_Edmons_Karp{
public:
  Graph graph;
  Graph residual;
  int mf, f;
  vector<int>p;

  Fluxo_Edmons_Karp () {};
  Fluxo_Edmons_Karp(Graph graph);

  void augment(int v, int min_edge);
  Graph solve();
};

#endif

