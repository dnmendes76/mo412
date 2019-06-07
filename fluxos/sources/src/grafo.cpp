#include "grafo.h"

void Graph::load_grafo(string path) {
  //cout << "Lendo Arquivo" << endl;

  ifstream file;
  file.open(path, fstream::in);
  file >> n >> m >> s >> t;
  Aresta e, aux;
  m_adj.resize(n);
  for (int i = 0; i < n; i++) m_adj[i].resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      m_adj[i][j] = 0;
  for (int i = 0; i < m; i++) {
    file >> e.u >> e.v >> e.custo;
    m_adj[e.u][e.v] = e.custo;
  }

  //cout << "Arquivo Carregado" << endl;
  file.close();
}

void Graph::print_grafo() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << '(' << m_adj[i][j] << ") ";
    }
    cout << endl;
  }
}
