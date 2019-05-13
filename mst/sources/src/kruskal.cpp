#include "../inc/kruskal.h"
#include "../inc/union_find.h"

MST_Kruskal::MST_Kruskal(Graph graph) {
    this->graph = graph;
}

Soluction MST_Kruskal::solve_without_heuristics() {
    UnionFind set(graph.n);
    for (int i = 0; i < graph.n; i++)
        set.make_set(i);

    sort(graph.arestas.begin(), graph.arestas.end());

    Soluction soluction;
    for (int i = 0; i < graph.m; i++) {
        Aresta e = graph.arestas[i];
        if (!set.same_set_with_find_set_default(e.u, e.v)) {
            set.union_set_with_find_default(e.u, e.v);
            soluction.valor += e.peso;
            soluction.arestas.push_back(e);
        }
    }
    return soluction;
}

Soluction MST_Kruskal::solve_with_heuristic_path_compression() {
    UnionFind set(graph.n);
    for (int i = 0; i < graph.n; i++)
        set.make_set(i);

    sort(graph.arestas.begin(), graph.arestas.end());

    Soluction soluction;
    for (int i = 0; i < graph.m; i++) {
        Aresta e = graph.arestas[i];
        if (!set.same_set_with_find_path_compression(e.u, e.v)) {
            set.union_set_with_path_compression(e.u, e.v);
            soluction.valor += e.peso;
            soluction.arestas.push_back(e);
        }
    }
    return soluction;
}

Soluction MST_Kruskal::solve_with_heuristic_union_by_rank() {
    UnionFind set(graph.n);
    for (int i = 0; i < graph.n; i++)
        set.make_set(i);

    sort(graph.arestas.begin(), graph.arestas.end());

    Soluction soluction;
    for (int i = 0; i < graph.m; i++) {
        Aresta e = graph.arestas[i];
        if (!set.same_set_with_find_set_default(e.u, e.v)) {
            set.union_by_rank_with_find_default(e.u, e.v);
            soluction.valor += e.peso;
            soluction.arestas.push_back(e);
        }
    }
    return soluction;
}

Soluction MST_Kruskal::solve_with_both_heuristics() {
    UnionFind set(graph.n);
    for (int i = 0; i < graph.n; i++)
        set.make_set(i);

    sort(graph.arestas.begin(), graph.arestas.end());

    Soluction soluction;
    for (int i = 0; i < graph.m; i++) {
        Aresta e = graph.arestas[i];
        if (!set.same_set_with_find_path_compression(e.u, e.v)) {
            set.union_by_rank_with_path_compression(e.u, e.v);
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
        if (!set->same_set_with_find_path_compression(e.u, e.v)) {
            set->union_by_rank_with_path_compression(e.u, e.v);
            solution.arestas.push_back(e);
            solution.valor += e.peso;
        }
    }

    return solution;
}