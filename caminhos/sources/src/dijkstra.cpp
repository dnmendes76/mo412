#include "dijkstra.h"

Dijkstra::Dijkstra(Graph *graph) {
    this->graph = graph;
    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
}

bool Dijkstra::relax(int u, int v) {
    double dist = distance[u] + graph->get_weight(u, v);
    if (distance[v] > dist) {
        distance[v] = dist;
        pi[v] = u;
        return true;
    }
    return false;
}

void Dijkstra::solve_vector() {
    vector<double> heap = vector<double>(graph->n);
    vector<bool> in_heap = vector<bool>(graph->n);
    double min;
    int size_heap = graph->n;
    int v, u = 0;
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT16_MAX;
        pi[i] = -1;
        heap[i] = distance[i];
        in_heap[i] = 1;
    }
    heap[graph->s] = 0.0;
    distance[graph->s] = 0;

    while(size_heap != 0) {
        min = INT16_MAX;
        for(int i=0; i<(int)heap.size(); i++){
            if(!in_heap[i]) continue;
            if(heap[i] < min) {
                u = i;
                min = heap[i];
            }
        }
        size_heap--;
        in_heap[u] = 0;

        for(int i=0; i<(int)graph->adj[u].size(); i++) {
            v =  graph->adj[u][i].v;
            if(relax(u, v)) {
                heap[v] = distance[v];
            }
        }
    }
}

void Dijkstra::solve_heap_binary() {
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

void Dijkstra::solve_heap_fibonacci() {
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