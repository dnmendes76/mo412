#ifndef JOHNSON_H
#define JOHNSON_H

#include "caminho_minimo.h"

class Johnson : public CaminhoMinimo{
	Graph* modify_graph();
	Graph* update_graph(vector<double> distance);
	
public:
	Johnson(Graph* graph);
	void solve();
};

#endif