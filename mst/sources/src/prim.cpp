#include "../inc/prim.h"
#include "../inc/heap_binary.h"
#include "../inc/heap_vector.h"
#include "../inc/heap_fibonacci.h"

MST_Prim::MST_Prim(Graph graph){
  this->graph = graph;
  this->parent.resize(graph.n);
}

Soluction MST_Prim::obter_soluction() {
  Aresta e;
  Soluction soluction;
  for(int i = 0; i < graph.n; i++){
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

Soluction MST_Prim::solve_heap_vector(int root) {
  HeapVector heap(graph.n);
  heap.build_heap(graph.n);
  heap.decrease_key(root, 0.0);
  for(int i = 0; i < graph.n; i++) parent[i] = Par(-1, 0);
  while (heap.qtd_fila != 0) {
    int u = heap.extract_min();
    for (int i = 0; i < (int)graph.adj[u].size(); i++) {
      int v = graph.adj[u][i].v;
      double p = graph.adj[u][i].peso;
      if (heap.in_heap[v] && p < heap.valores[v]) {
        Par tmp(u, p);
        parent[v] = tmp;
        heap.decrease_key(v, p);
      }
    }
  }
  return obter_soluction();
}

Soluction MST_Prim::solve_heap_binary(int root) {
  HeapBinary heap(graph.n);
  vector<int>visitado;
  vector<double>dist;
  visitado.resize(graph.n);
  dist.resize(graph.n);
  Node temp;

  for(int i = 0; i < graph.n; i++) {
    parent[i] = Par(-1, 0);
    visitado[i] = 0;
    dist[i] = numeric_limits<double>::max();
  }

  dist[root] = 0.0;
  temp.vertice = root; temp.valor = 0.0; temp.last = -1;
  heap.heap_insert(temp);

  while(heap.size > 0) {
    Node u = heap.extract_min();
    if (visitado[u.vertice]) continue;
    visitado[u.vertice] = 1;
    Par tmp(u.last, dist[u.vertice]);
    parent[u.vertice] = tmp;
    for (int i = 0; i < (int)graph.adj[u.vertice].size(); i++) {
      int v = graph.adj[u.vertice][i].v;
      double p = graph.adj[u.vertice][i].peso;
      if (dist[v] > p) {
        dist[v] = p;
        temp.vertice = v; temp.valor = p; temp.last = u.vertice;
        heap.heap_insert(temp);
      }
    }
  }
  return obter_soluction();
}

Soluction MST_Prim::solve_heap_fibonacci_use_insert(int root){
  HeapFibonacci heap;

  vector<bool> visitado;
  vector<double> dist;
  dist.resize(graph.n);
  visitado.resize(graph.n);

  for(int i=0; i<graph.n; i++){
    parent[i] = Par(-1, 0);
    visitado[i] = false;
    dist[i] = numeric_limits<double>::max();
  }
  heap.insert(0.0, root);
  dist[root] = 0.0;

  while(heap.size > 0) {
    Par u(heap.H->vertice, heap.H->value);
    heap.extract_min();
    for(int i=0; i < (int)graph.adj[u.vertice].size(); i++) {
      int v = graph.adj[u.vertice][i].v;
      double peso = graph.adj[u.vertice][i].peso;
      if(!visitado[v] && peso < dist[v]) {
        u.peso = peso;
        parent[v] = u;
        dist[v] = peso;
        heap.insert(peso, v);
      }
    }
    visitado[u.vertice] = true;
  }
  return obter_soluction();
}

Soluction MST_Prim::solve_heap_fibonacci_use_decrease(int root){
  HeapFibonacci heap;
  NodeFibonacci* vertice_nodes[graph.n];
  vector<bool> visitado;

  for(int i=0; i<graph.n; i++){
    parent[i] = Par(-1, 0);
    visitado.push_back(false);
    vertice_nodes[i] = heap.insert(numeric_limits<double>::max(), i);
  }
  heap.decrease_key(vertice_nodes[root], 0.0);
  while(heap.size > 0) {
    Par u(heap.H->vertice, heap.H->value);
    heap.extract_min();
    for(int i=0; i < (int)graph.adj[u.vertice].size(); i++) {
      int v = graph.adj[u.vertice][i].v;
      double peso = graph.adj[u.vertice][i].peso;
      if(!visitado[v] && peso < vertice_nodes[v]->value) {
        u.peso = peso;
        parent[v] = u;
        heap.decrease_key(vertice_nodes[v], peso);
      }
    }
    visitado[u.vertice] = true;
  }
  return obter_soluction();
}
