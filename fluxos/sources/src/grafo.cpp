#include "grafo.h"

void Graph::load_grafo(string path) {
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
    if (m_adj[e.v][e.u]) {
      m_adj.resize(n + 1);
      for (int j = 0; j < n; j++) m_adj[j].resize(n + 1, 0);
      m_adj[n].resize(n + 1, 0);
      m_adj[e.u][n] = m_adj[n][e.v] = e.custo;
      n++;
    }
    else m_adj[e.u][e.v] += e.custo;
  }
  for (int i = 0; i < n; i++) {
    m_adj[i].resize(n, 0);
  }
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
