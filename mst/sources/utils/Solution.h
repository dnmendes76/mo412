//
// Created by carlos on 08/05/19.
//

#ifndef SOURCES_SOLUTION_H
#define SOURCES_SOLUTION_H

#include "includes.h"
#include "Edge.h"

class Solution {
    double total_weight;
    vector<Edge *> edges;

public:

    Solution();

    void insert_edge(Edge *edge);

    Edge *get_edge(int i);

};


#endif //SOURCES_SOLUTION_H
