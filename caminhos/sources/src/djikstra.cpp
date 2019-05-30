#include <heap_binary.h>
#include "djikstra.h"

Djikstra::Djikstra(Graph *graph) {
    this->graph = graph;
    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
    heap = new HeapBinary(graph->n);
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT32_MAX, pi[i] = -1;
        Node node;
        node.vertice = i, node.valor = distance[i];
    }

    distance[graph->s] = 0;
    Node node;
    node.vertice = graph->s, node.valor = distance[0];
    heap->heap_insert(node);

}

void Djikstra::relax(int u, int v, int heap_position) {
    if (distance[v] > distance[u] + graph->get_weight(u, v)) {
        distance[v] = distance[u] + graph->get_weight(u, v);
        Node node;
        node.vertice = v, node.valor = distance[v];
        heap->heap_insert(node);
        pi[v] = u;
    }
}

void Djikstra::solve() {
    Node u;
    int v;
    vector<Edge> adj;
    while (heap->size > 0) {
        u = heap->extract_min();
        adj = graph->adj[u.vertice];
        for (v = 0; v < int(adj.size()); v++) {
            relax(u.vertice, adj[v].v, adj[v].v);
        }
    }
}