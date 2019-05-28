#ifndef CAMINHO_MINIMO_H
#define CAMINHO_MINIMO_H

#include "graph.h"

class CaminhoMinimo{
public:
	Graph *graph;
    vector<double> distance;
    vector<int> pi;
    vector<vector<int>> pi_all_pairs;
    vector<vector<double>> distance_all_pairs;

    CaminhoMinimo() {}
};

#endif