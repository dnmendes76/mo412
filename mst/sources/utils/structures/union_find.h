//
// Created by carlos on 08/05/19.
//

#ifndef MST_UNION_FIND_H
#define MST_UNION_FIND_H


#include <utils/Graph.h>

class union_find {
    Graph * graph;
    vector<int> parent, rank;

public:
    union_find(Graph *graph);

    void make_set(int x);

    int find_set(int i);

    int same_set(int i, int j);

    int union_sets(int i, int j);
};


#endif //MST_UNION_FIND_H
