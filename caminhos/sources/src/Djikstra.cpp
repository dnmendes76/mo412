//
// Created by carlos on 25/05/19.
//

#include <heap_binary.h>
#include "Djikstra.h"

Djikstra::Djikstra(Graph *graph) {
    this->graph = graph;

    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
    heap = new HeapBinary(graph->n);
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT32_MAX, pi[i] = -1;
        Node node;
        node.vertice = i, node.valor = distance[i];
        heap->heap_insert(node);
    }

    distance[graph->s] = 0;
    Node node;
    node.vertice = graph->s, node.valor = distance[0];
    heap->decrease_key(graph->s, node);

}

void Djikstra::relax(int u, int v, int heap_position) {
    if (distance[v] > distance[u] + graph->get_weight(u, v)) {
        distance[v] = distance[u] + graph->get_weight(u, v);
        Node node;
        node.vertice = v, node.valor = distance[v];
        heap->decrease_key(heap_position, node);
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

    // Showing output
    vector<int> path;
    double path_weight;
    int parent;
    for (int i = 0; i < graph->n; i++) {
        if (i != graph->s) {
            path = vector<int>();
            path_weight = 0;
            parent = i;
            while (parent != graph->s) {
                path.push_back(parent);
                if (pi[parent] == -1) break;
                path_weight += graph->get_weight(pi[parent], parent);
                parent = pi[parent];
            }
            if (int(path.size()) == 1 && parent != graph->s) {
                cout << "custo inf " << graph->s << " " << i << endl;
            } else {
                cout << "custo " << path_weight << " " << graph->s << " ";
                for (int k = int(path.size()) - 1; k >= 0; k--) {
                    cout << path[k] << " ";
                }
                cout << endl;
            }
        }
    }

}