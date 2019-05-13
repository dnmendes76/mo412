#include "../inc/kruskal.h"
#include "../inc/union_find.h"

MST_Kruskal::MST_Kruskal(Graph graph) {
    this->graph = graph;
}

MST_Kruskal::MST_Kruskal() {

}

Soluction MST_Kruskal::solve() {
    UnionFind set(graph.n);
    for (int i = 0; i < graph.n; i++)
        set.make_set(i);

    sort(graph.arestas.begin(), graph.arestas.end());

    Soluction soluction;
    for (int i = 0; i < graph.m; i++) {
        Aresta e = graph.arestas[i];
        if (!set.same_set(e.u, e.v)) {
            set.union_set(e.u, e.v);
            soluction.valor += e.peso;
            soluction.arestas.push_back(e);
        }
    }
    return soluction;
}

Soluction MST_Kruskal::solve(vector<Aresta> edges, UnionFind *set) {
    vector<Aresta> edges_return = vector<Aresta>(edges);
    sort(edges_return.begin(), edges_return.end());
    Soluction solution;

    for (auto e : edges_return) {
        if (set->find_set(e.u) != set->find_set(e.v)) {
            set->union_set(e.u, e.v);
            solution.arestas.push_back(e);
            solution.valor += e.peso;
        }
    }

    return solution;
}