#include "kruskal.h"

void make_set(int x, vi &parent, vi &rank) {
    parent[x] = x;
    rank[x] = 0;
}

int find_set(int i, vi &parent) {
    return (parent[i] == i) ? i : (parent[i] = find_set(parent[i], parent));
}

int same_set(int i, int j, vi &parent) {
    return find_set(i, parent) == find_set(j, parent);
}

void union_set(int i, int j, vi &parent, vi &rank) {
    int x, y;
    if (!same_set(i, j, parent)) {
        x = find_set(i, parent);
        y = find_set(j, parent);
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
}

bool compare(edge_t i, edge_t j) {
    return (i.weight - j.weight < EPS);
}

edges_list_t make_graph(FILE *input_file) {
    int m, u, v, i;
    double p;
    edges_list_t ret;
    fscanf(input_file, "%d %d", &ret.order, &m);
    for (i = 0; i < m; i++) {
        fscanf(input_file, "%d %d %lf", &u, &v, &p);
        ret.edges.push_back(edge_t(u, v, p));
    }
    return ret;
}

solution_t kruskal(FILE *input_file, int structure) {
    int i, u, v;
    double p;
    edges_list_t graph;
    solution_t ret;
    ret.sol = 0;
    graph = make_graph(input_file);
    vi parent(graph.order);
    vi rank(graph.order);
    for (i = 0; i < graph.order; i++) make_set(i, parent, rank);
    sort(graph.edges.begin(), graph.edges.end(), compare);
    for (i = 0; i < (int) graph.edges.size(); i++) {
        u = graph.edges[i].u;
        v = graph.edges[i].v;
        p = graph.edges[i].weight;
        if (find_set(u, parent) != find_set(v, parent)) {
            union_set(u, v, parent, rank);
            ret.sol += p;
            ret.edges.push_back(edge_t(u, v, p));
        }
    }
    return ret;
}

