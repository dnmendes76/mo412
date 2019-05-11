#include "../inc/prim.h"
#include "../inc/heap_binary.h"

MST_Prim::MST_Prim(Graph graph){
  this->graph = graph;
  this->parent.resize(graph.n);
}

Soluction MST_Prim::obter_soluction() {
  Aresta e;
  Soluction soluction;
  for(int i=0; i < graph.n; i++){
    if(parent[i].vertice != -1) {
      e.u = parent[i].vertice;
      e.v = i;
      e.peso = parent[i].peso;
      soluction.arestas.push_back(e);
      soluction.valor += e.peso;
    }
  }
  return soluction;
}

Soluction MST_Prim::solve_heap_binary(int root) {
  HeapBinary heap(graph.n);
  vector<bool> in_heap;
  in_heap.resize(graph.n);
  Node temp;

  for(int i = 0; i < graph.n; i++) {
    temp.vertice = i; temp.valor = numeric_limits<double>::max();
    heap.valores[i] = temp;
    heap.posicoes[i] = i;
    parent[i] = Par(-1, 0);
    in_heap[i] = true;
  }

  temp.vertice = root; temp.valor = 0.0;
  heap.valores[root] = temp;
  heap.build_heap(graph.n);

  while(heap.size > 0) {
    Node u = heap.extract_min();
    for (int i = 0; i < (int)graph.adj[u.vertice].size(); i++) {
      int v = graph.adj[u.vertice][i].v;
      double p = graph.adj[u.vertice][i].peso;
      if (in_heap[v] && p < heap.valores[heap.posicoes[v]].valor) {
        temp.vertice = v; temp.valor = p;
        Par tmp(u.vertice, p);
        parent[v] = tmp;
        heap.decrease_key(v, temp);
      }
    }
    in_heap[u.vertice] = false;
  }
  return obter_soluction();
}
