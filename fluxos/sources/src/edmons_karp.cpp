#include "../inc/edmons_karp.h"

Fluxo_Edmons_Karp::Fluxo_Edmons_Karp(Graph graph) {
    this->graph = graph;
}

void Fluxo_Edmons_Karp::augment(int v, int min_edge) {
  if (v == graph.s) { f = min_edge; return; }
  if (p[v] != -1) {
    augment(p[v], min(min_edge, residual.m_adj[p[v]][v]));
    residual.m_adj[p[v]][v] -= f;
    residual.m_adj[v][p[v]] += f;
  }
}

Graph Fluxo_Edmons_Karp::solve() {
  mf = 0;
  residual.m_adj.resize(graph.n);
  for (int i = 0; i < graph.n; i++)
    residual.m_adj[i].resize(graph.n);
  for (int i = 0; i < graph.n; i++)
    for (int j = 0; j < graph.n; j++)
      residual.m_adj[i][j] = graph.m_adj[i][j];
  while (true) {
    f = 0;
    vector<int> dist(graph.n, INF);
    dist[graph.s] = 0;
    queue<int>q;
    q.push(graph.s);
    p.assign(graph.n, -1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == graph.t) break;
      for (int v = 0; v < graph.n; v++)
        if (residual.m_adj[u][v] > 0 && dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.push(v);
          p[v] = u;
        }
    }
    augment(graph.t, INF);
    if (f == 0) break;
    mf += f;
  }
  cout << "Fluxo total: " << mf << endl;
  return residual;
}
