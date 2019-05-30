#include "djikstra.h"

Djikstra::Djikstra(Graph *graph) {
    this->graph = graph;
    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
}

bool Djikstra::relax(int u, int v) {
    double dist = distance[u] + graph->get_weight(u, v);
    if (distance[v] > dist) {
        distance[v] = dist;
        pi[v] = u;
        return true;
    }
    return false;
}

void solve_vector() {
    
}

void Djikstra::solve_heap_binary() {
    HeapBinary *heap = new HeapBinary(graph->n);
    Node node;
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT16_MAX;
        pi[i] = -1;
    }

    distance[graph->s] = 0;
    node.vertice = graph->s, node.valor = distance[graph->s];
    heap->heap_insert(node);

    Node u;
    vector<Edge> adj;
    while (heap->size > 0) {
        u = heap->extract_min();
        adj = graph->adj[u.vertice];
        for (int v = 0; v < int(adj.size()); v++) {
            if(relax(u.vertice, adj[v].v)) {
                node.vertice = adj[v].v, node.valor = distance[adj[v].v];
                heap->heap_insert(node);
            }
        }
    }
}

void Djikstra::solve_heap_fibonacci() {
    HeapFibonacci heap;
    int u, v;
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT16_MAX;
        pi[i] = -1;
    }

    distance[graph->s] = 0;
    heap.insert(0.0, graph->s);
    while(heap.size > 0) {
        u = heap.H->vertice;
        heap.extract_min();
        for(int i=0; i<(int)graph->adj[u].size(); i++) {
            v =  graph->adj[u][i].v;
            if(relax(u, v)){
                heap.insert(distance[v], v);
            }
        }
    }
}