#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "caminho_minimo.h"

class BellmanFord : public CaminhoMinimo{
	bool relax(int u, int v);

public:
    bool has_negative_cycle = false;
	BellmanFord(Graph *graph);

    void solve();
    void solve_two();

};


#endif
