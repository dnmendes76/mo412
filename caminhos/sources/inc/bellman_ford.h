#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "caminho_minimo.h"

class BellmanFord : public CaminhoMinimo{

public:
    bool has_negative_cycle = false;

    BellmanFord(Graph *graph);

    void relax(int u, int v);

    void solve();
};


#endif
