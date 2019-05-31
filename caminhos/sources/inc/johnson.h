#ifndef JOHNSON_H
#define JOHNSON_H

#include "caminho_minimo.h"

class Johnson : public CaminhoMinimo{
	void initialize();
	Graph* modify_graph();
	Graph* update_graph(vector<double> distance);
	
public:
	Johnson(Graph* graph);
	void solve_dijkstra_vector();
	void solve_dijkstra_heap_bin();
	void solve_dijkstra_heap_fibo();

};

#endif