//
// Created by carlos on 11/05/19.
//

#include "../inc/filter_kruskal.h"
#include "../inc/kruskal.h"
#include "../inc/union_find.h"

MST_Filter_Kruskal::MST_Filter_Kruskal(Graph graph) {
    this->threshold = 30;
    this->graph = Graph(graph);
    this->kruskal_solver = MST_Kruskal(graph);
}

Soluction MST_Filter_Kruskal::solve() {
    UnionFind *set = new UnionFind(graph.n);
    for (int i = 0; i < graph.n; i++)
        set->make_set(i);

    this->edges = vector<Aresta>();
    vector<Aresta> a = vector<Aresta>();
    for (int i = 0; i < graph.n; i++) {
        for (int j = 0; j < int(graph.adj[i].size()); j++) {
            Aresta e = graph.adj[i][j];
            if (e.u < e.v) {
                edges.push_back(e);
            }
        }
    }

    vector<Aresta> *greater = new vector<Aresta>();
    vector<Aresta> *leq = new vector<Aresta>();


    vector<Aresta> solution_edges = kruskal(edges, leq, greater, set, a);
    Soluction solution;

    for (Aresta edge : solution_edges) {
        solution.arestas.push_back(edge);
        solution.valor += edge.peso;
    }

    return solution;
}

void MST_Filter_Kruskal::partition(vector<Aresta> edges, vector<Aresta> *leq, vector<Aresta> *greater, int pivot) {
    leq->resize(0);
    greater->resize(0);

    for (auto edge : edges) {
        if (edge.peso <= edges[pivot].peso) {
            leq->push_back(edge);
        } else {
            greater->push_back(edge);
        }
    }
}

vector<Aresta> MST_Filter_Kruskal::filter(vector<Aresta> edges, UnionFind *set) {
    vector<Aresta> filtered = vector<Aresta>();
    for (auto edge : edges) {
        if (set->find_set_path_compression(edge.u) != set->find_set_path_compression(edge.v)) {
            filtered.push_back(edge);
        }
    }
    return filtered;
}

vector<Aresta>
MST_Filter_Kruskal::kruskal(vector<Aresta> edges, vector<Aresta> *leq, vector<Aresta> *greater, UnionFind *set,
                            vector<Aresta> a) {
    if (this->threshold >= int(edges.size())) {
        return kruskal_solver.solve(edges, set).arestas;
    }

    int pivot = int(random() % int(edges.size()));

    vector<Aresta> *edges_leq = new vector<Aresta>(*leq);
    vector<Aresta> *edges_greater = new vector<Aresta>(*greater);

    partition(edges, edges_leq, edges_greater, pivot);

    a = kruskal(*edges_leq, leq, greater, set, a);

    edges_greater = new vector<Aresta>(filter(*edges_greater, set));

    vector<Aresta> edges_aux = kruskal(*edges_greater, leq, greater, set, a);

    a.insert(a.end(), edges_aux.begin(), edges_aux.end());

    return a;
}