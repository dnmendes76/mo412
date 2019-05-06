#include "kruskal.h"

void make_set(int x, vi &pai, vi &ra) { pai[x] = x; ra[x] = 0; }

int find_set(int i, vi &pai) { return (pai[i] == i) ? i : (pai[i] = find_set(pai[i], pai)); }

int isSameSet(int i, int j, vi &pai) { return find_set(i, pai) == find_set(j, pai);  }

void union_set(int i, int j, vi &pai, vi &ra) {
  int x, y;
  if (!isSameSet(i, j, pai)) {
    x = find_set(i, pai); y = find_set(j, pai);
    if (ra[x] > ra[y]) pai[y] = x;
    else {
      pai[x] = y;
      if (ra[x] == ra[y]) ra[y]++;
    }
  }
}

bool compara(aresta_t i, aresta_t j) { return (i.peso - j.peso < EPS); }

lista_arestas_t monta_grafo(FILE *entrada) {
  int m, u, v, i;
  double p;
  lista_arestas_t ret;
  fscanf(entrada, "%d %d", &ret.ordem, &m);
  for (i = 0; i < m; i++) {
    fscanf(entrada, "%d %d %lf", &u, &v, &p);
    ret.arestas.push_back(aresta_t(u, v, p));
  }
  return ret;
}

solucao_t kruskal(FILE *entrada){
  int i, u, v;
  double p;
  lista_arestas_t grafo;
  solucao_t ret;
  ret.sol = 0;
  grafo = monta_grafo(entrada);
  vi pai(grafo.ordem); vi ra(grafo.ordem);
  for (i = 0; i < grafo.ordem; i++) make_set(i, pai, ra);
  sort(grafo.arestas.begin(), grafo.arestas.end(), compara);
  for (i = 0; i < (int)grafo.arestas.size(); i++) {
    u = grafo.arestas[i].u; v = grafo.arestas[i].v; p = grafo.arestas[i].peso;
    if (find_set(u, pai) != find_set(v, pai)) {
      union_set(u, v, pai, ra);
      ret.sol += p;
      ret.arestas.push_back(aresta_t(u, v, p));
    }
  }
  return ret;
}

