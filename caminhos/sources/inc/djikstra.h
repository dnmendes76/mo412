#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include "caminho_minimo.h"
#include "heap_binary.h"

class Djikstra : public CaminhoMinimo{

public:
    HeapBinary * heap;
    Djikstra(Graph *graph);

    void relax(int u, int v, int heap_position);
    void solve();

};

#endif
