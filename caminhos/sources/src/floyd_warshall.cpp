#include "floyd_warshall.h"

FloydWarshall::FloydWarshall(Graph *graph) {
    this->graph = graph;
    this->distance_all_pairs = vector<vector<double>>(graph->n, vector<double>(graph->n));
    this->pi_all_pairs = vector<vector<int>>(graph->n, vector<int>(graph->n));

    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            distance_all_pairs[i][j] = graph->adjMatrix[i][j];
            pi_all_pairs[i][j] = -1;
            if(i != j && graph->adjMatrix[i][j] == 0) {
                distance_all_pairs[i][j] = INT32_MAX;
            }
            if (i != j && graph->adjMatrix[i][j] != INT32_MAX && graph->adjMatrix[i][j] != 0) {
                pi_all_pairs[i][j] = i;
            }
        }
    }
}

void FloydWarshall::solve() {
    int n = graph->n;
    double peso;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                peso = distance_all_pairs[i][k] + distance_all_pairs[k][j];
                if ( peso < distance_all_pairs[i][j]) {
                    distance_all_pairs[i][j] = peso;
                    pi_all_pairs[i][j] = pi_all_pairs[k][j];
                }
            }
        }
    }
}