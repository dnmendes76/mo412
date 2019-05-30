#ifndef CAMINHO_MINIMO_H
#define CAMINHO_MINIMO_H

#include "graph.h"

class CaminhoMinimo{
public:
	Graph *graph;
    vector<double> distance;
    vector<int> pi;
    vector<vector<int>> pi_all_pairs;
    vector<vector<double>> distance_all_pairs;

    CaminhoMinimo() {}

    void salve_soluction(string out) {
    	vector<int> path;
    	int parent;
    	ofstream file;
	    file.open(out);

    	for (int i = 0; i < graph->n; i++) {
	        if (i != graph->s) {
	            path = vector<int>();
	            parent = i;
	            while (parent != graph->s) {
	                path.push_back(parent);
	                if (pi[parent] == -1) break;
	                parent = pi[parent];
	            }
	            if (int(path.size()) == 1 && parent != graph->s) {
	                file << "custo inf " << graph->s << " " << i << endl;
	            } else {
	                file << "custo " << distance[i] << " " << graph->s << " ";
	                for (int k = int(path.size()) - 1; k >= 0; k--) {
	                    file << path[k] << " ";
	                }
	                file << endl;
	            }
	        }
	    }
        file.close();
    }

    void salve_soluction_all_pairs(string out) {
    	ofstream file;
	    file.open(out);
    	vector<int> path;
	    int parent;
	    int n = graph->n;
	    for (int i = 0; i < n; i++) {
	        file << "custo " << 0 << " " << i << " " << i << endl;
	        for (int j = 0; j < n; ++j) {
	            if (j != i) {
	                path = vector<int>();
	                parent = j;
	                while (parent != i) {
	                    path.push_back(parent);
	                    if (pi_all_pairs[i][parent] == -1) break;
	                    parent = pi_all_pairs[i][parent];
	                }

	                if (int(path.size()) == 1 && parent != i) {
	                    file << "custo inf " << i << " " << j << endl;
	                } else {
	                    file << "custo " << distance_all_pairs[i][j] << " " << i << " ";
	                    for (int k = int(path.size()) - 1; k >= 0; k--) {
	                        file << path[k] << " ";
	                    }
	                    file << endl;
	                }
	            }
	        }
	    }
	    file.close();
    }

};

#endif