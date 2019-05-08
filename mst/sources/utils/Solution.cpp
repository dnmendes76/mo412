//
// Created by carlos on 08/05/19.
//

#include "Solution.h"

Solution::Solution() {
    this->edges = vector<Edge *>();
    this->total_weight = 0;
}

void Solution::insert_edge(Edge *edge) {
    this->edges.push_back(edge);
}

Edge *Solution::get_edge(int i) {
    return (i < int(this->edges.size())) ? this->edges[i] : nullptr;
}