//
// Created by carlos on 25/05/19.
//

#ifndef SHP_BELLMAN_FORD_DJIKSTRA_H
#define SHP_BELLMAN_FORD_DJIKSTRA_H

#include "graph.h"
#include "heap_binary.h"

class Djikstra {

public:
    Graph *graph;
    vector<double> distance;
    vector<int> pi;
    HeapBinary * heap;

    Djikstra(Graph *graph);

    void relax(int u, int v, int heap_position);

    void solve();

};


#endif //SHP_BELLMAN_FORD_DJIKSTRA_H
