//
// Created by carlos on 08/05/19.
//

#include "union_find.h"

union_find::union_find(Graph *graph) {
    this->graph = graph;
    this->rank = vector<int>(graph->V);
    this->parent = vector<int>(graph->V);

    for (int i = 0; i < graph->V; i++) make_set(i);


}

void union_find::make_set(int x) {
    this->parent[x] = x;
    this->rank[x] = 0;
}

int union_find::find_set(int i) {
    return (this->parent[i] == i) ? i : (parent[i] = find_set(this->parent[i]));
}

int union_find::same_set(int i, int j) {
    return find_set(i) == find_set(j);
}

int union_find::union_sets(int i, int j) {
    int x, y;
    if (!same_set(i, j)) {
        x = find_set(i);
        y = find_set(j);
        if (this->rank[x] > this->rank[y]) {
            this->parent[y] = x;
        } else {
            this->parent[x] = y;
            if (this->rank[x] == this->rank[y]) {
                this->rank[y]++;
            }
        }
    }
}