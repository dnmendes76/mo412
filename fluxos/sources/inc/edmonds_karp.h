#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include "grafo.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 112345678

class Fluxo_Edmonds_Karp{
public:
  Graph graph;
  Graph residual;
  int mf, f;
  vector<int>p;

  Fluxo_Edmonds_Karp () {};
  Fluxo_Edmonds_Karp(Graph graph);

  void augment(int v, int min_edge);
  Graph solve();
};

#endif

