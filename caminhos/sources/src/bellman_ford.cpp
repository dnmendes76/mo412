#include "bellman_ford.h"

BellmanFord::BellmanFord(Graph *graph) {
    this->graph = graph;
    this->distance = vector<double>(graph->n);
    this->pi = vector<int>(graph->n);
}

bool BellmanFord::relax(int u, int v) {
    double dist = distance[u] + graph->get_weight(u, v);
    if (distance[v] > dist) {
        distance[v] = dist;
        pi[v] = u;
        return true;
    }
    return false;
}

void BellmanFord::solve() {
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT32_MAX;
        pi[i] = -1;
    }
    distance[graph->s] = 0;

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
}

void BellmanFord::solve_two() {
    bool flag = false;
    for (int i = 0; i < graph->n; i++) {
        distance[i] = INT32_MAX;
        pi[i] = -1;
    }
    distance[graph->s] = 0;

    for (int i = 0; i < graph->n; i++) {
        for (Edge edge : graph->edges) {
            if(relax(edge.u, edge.v)) {
                flag = true;
            }
        }
        if(!flag) break;
    }
    int u, v;
    for (Edge edge : graph->edges) {
        u = edge.u, v = edge.v;
        if (distance[v] > distance[u] + graph->get_weight(u, v)) {
            has_negative_cycle = true;
            break;
        }
    }
}