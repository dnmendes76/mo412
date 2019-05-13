#ifndef SOURCES_FILTER_KRUSKAL_H
#define SOURCES_FILTER_KRUSKAL_H

#include "../inc/grafo.h"
#include "vector"
#include "../inc/union_find.h"
#include "../inc/kruskal.h"

class MST_Filter_Kruskal {
    int threshold;
    Graph graph;
    vector<Aresta> edges;
    MST_Kruskal kruskal_solver;

    void partition(vector<Aresta> edges, vector<Aresta> *leq, vector<Aresta> *greater, int pivot);

public:

    MST_Filter_Kruskal(Graph graph);

    Soluction solve();

    vector<Aresta> kruskal(vector<Aresta> edges, vector<Aresta> *leq, vector<Aresta> *greater, UnionFind *set, vector<Aresta> a);

    vector<Aresta> filter(vector<Aresta> edges, UnionFind *set);

};


#endif //SOURCES_FILTER_KRUSKAL_H