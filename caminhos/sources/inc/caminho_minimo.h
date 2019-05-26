#ifndef CAMINHO_MINIMO_H
#define CAMINHO_MINIMO_H

#include "graph.h"

class CaminhoMinimo{
public:
	Graph *graph;
    vector<double> distance;
    vector<int> pi;

    CaminhoMinimo() {}
};

#endif