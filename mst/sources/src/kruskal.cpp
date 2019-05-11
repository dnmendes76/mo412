#include "../inc/kruskal.h"
#include "../inc/union_find.h"

MST_Kruskal::MST_Kruskal(Graph graph){
	this->graph = graph;
}

Soluction MST_Kruskal::solve(){
  UnionFind set(graph.n);
  for(int i=0; i<graph.n; i++)
    set.make_set(i);

  sort(graph.arestas.begin(), graph.arestas.end());

  Soluction soluction;
  for (int i = 0; i < graph.m; i++) {
    Aresta e = graph.arestas[i];
    if(!set.same_set(e.u, e.v)) {
      set.union_set(e.u, e.v);
      soluction.valor += e.peso;
      soluction.arestas.push_back(e);
    }
  }
  return soluction;
}
