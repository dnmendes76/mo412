#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include "caminho_minimo.h"
#include "heap_binary.h"
#include "heap_fibonacci.h"

class Dijkstra : public CaminhoMinimo{

public:
    Dijkstra(Graph *graph);

    bool relax(int u, int v);
    void solve_vector();
    void solve_heap_binary();
    void solve_heap_fibonacci();

};

#endif
