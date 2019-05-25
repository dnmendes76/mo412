//
// Created by carlos on 25/05/19.
//

#ifndef SHP_BELLMAN_FORD_BELLMAN_FORD_H
#define SHP_BELLMAN_FORD_BELLMAN_FORD_H


#include "graph.h"

class Bellman_Ford {
public:
    Graph *graph;
    vector<double> distance;
    vector<int> pi;
    bool has_negative_cycle = false;

    Bellman_Ford(Graph *graph);

    void relax(int u, int v);

    void solve();
};


#endif //SHP_BELLMAN_FORD_BELLMAN_FORD_H
