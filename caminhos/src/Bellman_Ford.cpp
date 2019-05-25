//
// Created by carlos on 25/05/19.
//

#include "Bellman_Ford.h"

Bellman_Ford::Bellman_Ford(Graph *graph) {
    this->graph = graph;

    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
    for (int i = 0; i < graph->n; i++)
        distance[i] = INT32_MAX, pi[i] = -1;

    distance[graph->s] = 0;
}

void Bellman_Ford::relax(int u, int v) {
    if (distance[v] > distance[u] + graph->get_weight(u, v)) {
        distance[v] = distance[u] + graph->get_weight(u, v);
        pi[v] = u;
    }
}

void Bellman_Ford::solve() {
    for (int i = 0; i < graph->n; i++) {
        for (Edge edge : graph->edges) {
            relax(edge.u, edge.v);
        }
    }
    int u, v;
    for (Edge edge : graph->edges) {
        u = edge.u, v = edge.v;
        if (distance[v] > distance[u] + graph->get_weight(u, v)) {
            has_negative_cycle = true;
            break;
        }
    }

    // Showing output
    vector<int> path;
    double path_weight;
    int parent;
    if (!has_negative_cycle) {
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
}