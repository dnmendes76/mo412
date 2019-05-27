//
// Created by carlos on 26/05/19.
//

#ifndef SHP_BELLMAN_FORD_FLOYD_WARSHALL_H
#define SHP_BELLMAN_FORD_FLOYD_WARSHALL_H

#include "graph.h"

class Floyd_Warshall {
public:
    Graph *graph;
    vector<vector<double>> distance;
    vector<vector<int>> pi;

    Floyd_Warshall(Graph *graph);

    void solve();

};


#endif //SHP_BELLMAN_FORD_FLOYD_WARSHALL_H
