#include "graph.h"

void Graph::load_graph(string path) {
    //cout << "Lendo Arquivo" << endl;

    ifstream file;
    file.open(path, fstream::in);
    file >> n >> m >> s;
    Edge e;
    adj.resize(n);
    adjMatrix = vector<vector<double>>(n, vector<double>(n));

    for (int i = 0; i < m; i++) {
        file >> e.u >> e.v >> e.weight;
        adjMatrix[e.u][e.v] = e.weight;
        adj[e.u].push_back(e);
        edges.push_back(e);
    }

    //cout << "Arquivo Carregado" << endl;
    file.close();
}

void Graph::print_grafo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < int(adj[i].size()); j++) {
            Edge e = adj[i][j];
            cout << '(' << e.u << ',' << e.v << ") - " << e.weight << endl;
        }
    }
}

double Graph::get_weight(int u, int v) {
    return this->adjMatrix[u][v];
}
