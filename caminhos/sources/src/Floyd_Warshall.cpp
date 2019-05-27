//
// Created by carlos on 26/05/19.
//

#include "Floyd_Warshall.h"

Floyd_Warshall::Floyd_Warshall(Graph *graph) {
    this->graph = graph;
    this->distance = vector<vector<double>>(graph->n, vector<double>(graph->n));
    pi = vector<vector<int>>(graph->n, vector<int>(graph->n));

    for (int i = 0; i < graph->n; i++) {
        this->distance[i][i] = 0;
    }
}

void Floyd_Warshall::solve() {
    int k, i, j, n = graph->n;
    vector<vector<double>> d = vector<vector<double>>(n, vector<double>(n));
    vector<vector<int>> pi_aux = vector<vector<int>>(n, vector<int>(n));

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            d[i][j] = graph->adjMatrix[i][j];
            pi_aux[i][j] = -1;
            if (d[i][j] == 0)
                d[i][j] = INT16_MAX;
            if (i == j)
                d[i][j] = 0;
            if (i != j && graph->adjMatrix[i][j] != INT16_MAX && graph->adjMatrix[i][j] != 0)
                pi_aux[i][j] = i;
        }
    }


    for (k = 0; k < n; k++) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    distance[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi_aux[k][j];
                } else {
                    distance[i][j] = d[i][j];
                    pi[i][j] = pi_aux[i][j];
                }
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                d[i][j] = distance[i][j];
                pi_aux[i][j] = pi[i][j];
                distance[i][j] = INT16_MAX;
                pi[i][j] = -1;
            }
        }
    }

/**
    for (i = 0; i < n; ++i) {
        cout << "i - " << i << ": ";
        for (j = 0; j < n; ++j) {
            if (d[i][j] > 100)
                cout << "N ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;

    for (i = 0; i < n; ++i) {
        cout << "i - " << i << ": ";
        for (j = 0; j < n; ++j) {
            cout << pi_aux[i][j] << " ";
        }
        cout << endl;
    }
**/

    // Showing output
    vector<int> path;
    double path_weight;
    int parent;
    for (i = 0; i < n; i++) {
        cout << "custo " << 0 << " " << i << " " << i << endl;
        for (j = 0; j < n; ++j) {
            if (j != i) {
                path = vector<int>();
                path_weight = 0;
                parent = j;
                while (parent != i) {
                    path.push_back(parent);
                    if (pi_aux[i][parent] == -1) break;
                    path_weight += d[pi_aux[i][parent]][parent];
                    parent = pi_aux[i][parent];
                }

                if (int(path.size()) == 1 && parent != i) {
                    cout << "custo inf " << i << " " << j << endl;
                } else {
                    cout << "custo " << path_weight << " " << i << " ";
                    for (k = int(path.size()) - 1; k >= 0; k--) {
                        cout << path[k] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}