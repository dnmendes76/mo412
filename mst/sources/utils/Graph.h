//
// Created by carlos on 08/05/19.
//

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include "Edge.h"
#include "includes.h"

class Graph {
    vector<Edge *> graph;

public:

    int V, E;

    Graph(FILE *input_file);

    Edge *get_edge(int i);

    void add_edge(int i, int j, double weight);

    void sort_by_edge();
};


#endif //MST_GRAPH_H
