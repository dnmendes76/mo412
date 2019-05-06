#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 10e-9

struct aresta_t { int u, v; double peso; aresta_t() {}
aresta_t(int _u, int _v, double _peso): u(_u), v(_v), peso(_peso) {} };

typedef vector<int>vi;
typedef vector<aresta_t>v_aresta;
typedef struct { v_aresta arestas; int ordem; }lista_arestas_t;
typedef struct { v_aresta arestas; double sol; }solucao_t;

solucao_t kruskal(FILE *entrada);

#endif
