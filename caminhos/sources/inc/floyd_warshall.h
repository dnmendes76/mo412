#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "caminho_minimo.h"

class FloydWarshall : public CaminhoMinimo{
public:
    FloydWarshall(Graph *graph);

    void solve();

};


#endif 
