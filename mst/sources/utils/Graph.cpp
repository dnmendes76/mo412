//
// Created by carlos on 08/05/19.
//

#include "Graph.h"

Graph::Graph(FILE *input_file) {
    this->graph = vector<Edge *>();
    int u, v;
    double w;

    fscanf(input_file, "%d %d", &this->V, &this->E);

    for (int i = 0; i < this->E; i++) {
        fscanf(input_file, "%d %d %lf", &u, &v, &w);
        add_edge(u, v, w);
    }
}

Edge *Graph::get_edge(int i) {
    return (i < int(this->graph.size())) ? this->graph[i] : nullptr;
}

void Graph::add_edge(int i, int j, double weight) {
    this->graph.push_back(new Edge(i, j, weight));
}

bool compare(Edge e1, Edge e2) {
    return (e1.weight - e2.weight) < EPS;
}

void Graph::sort_by_edge() {
    sort(graph.begin(), graph.end(), compare);
}