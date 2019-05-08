#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define EPS 10e-9

struct edge_t {
    int u, v;
    double weight;

edge_t() {}

edge_t(int _u, int _v, double _weight) : u(_u), v(_v), weight(_weight) {} };

typedef vector<int>vi;
typedef vector<edge_t>v_edge;
typedef struct { v_edge edges; int order; } edges_list_t;
typedef struct { v_edge edges; double sol; } solution_t;

solution_t kruskal(FILE *input_file, int structure);

#endif
