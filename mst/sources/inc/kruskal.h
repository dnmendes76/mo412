#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "soluction.h"
#include "union_find.h"
#include <algorithm>

using namespace std;

class MST_Kruskal{
public:

	Graph graph;

	MST_Kruskal(Graph graph);

	MST_Kruskal();

	Soluction solve();

	Soluction solve(vector<Aresta> edges, UnionFind *set);

};

#endif

