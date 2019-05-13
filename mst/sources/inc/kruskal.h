#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "soluction.h"
#include "union_find.h"
#include <algorithm>

using namespace std;

class MST_Kruskal{
public:

	Graph graph;

	MST_Kruskal() {}
	MST_Kruskal(Graph graph);


	Soluction solve_without_heuristics();
	Soluction solve_with_heuristic_path_compression();
	Soluction solve_with_heuristic_union_by_rank();
	Soluction solve_with_both_heuristics();

	Soluction solve(vector<Aresta> edges, UnionFind *set);

};

#endif

