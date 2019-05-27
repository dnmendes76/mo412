#ifndef JOHNSON_H
#define JOHNSON_H

#include "caminho_minimo.h"

class Johnson : public CaminhoMinimo{
	Graph* modify_graph();
public:
	Johnson(Graph* graph);
	void solve();
};

#endif