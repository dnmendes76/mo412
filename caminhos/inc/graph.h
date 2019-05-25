#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
    int u;
    int v;
    double weight;

    Edge() {}

    Edge(int u, int v, double weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }

    bool operator<(const Edge &edge) const {
        return (this->weight < edge.weight);
    }
};

class Graph {
public:
    int n, m, s;
    vector<vector<Edge>> adj;
    vector<Edge> edges;
    vector<vector<double>> adjMatrix;

    Graph() {
    }

    void load_graph(string path);

    double get_weight(int u, int v);

    void print_grafo();
};

#endif
