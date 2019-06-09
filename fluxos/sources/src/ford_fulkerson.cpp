#include "../inc/ford_fulkerson.h"

Fluxo_Ford_Fulkerson::Fluxo_Ford_Fulkerson(Graph graph) {
    this->graph = graph;
}

void Fluxo_Ford_Fulkerson::augment(int v, int min_edge) {
  if (v == graph.s) { f = min_edge; return; }
  if (p[v] != -1) {
    augment(p[v], min(min_edge, residual.m_adj[p[v]][v]));
    residual.m_adj[p[v]][v] -= f;
    residual.m_adj[v][p[v]] += f;
  }
}

void Fluxo_Ford_Fulkerson::find_path(int u) {
  vis[u] = true;
  if (u == graph.t) return;
  for (int i = 0; i < graph.n; i++)
    if (!vis[i] && residual.m_adj[u][i]) {
      p[i] = u;
      find_path(i);
    }
}

Graph Fluxo_Ford_Fulkerson::solve() {
  mf = 0;
  residual.m_adj.resize(graph.n);
  for (int i = 0; i < graph.n; i++)
    residual.m_adj[i].resize(graph.n);
  for (int i = 0; i < graph.n; i++)
    for (int j = 0; j < graph.n; j++)
      residual.m_adj[i][j] = graph.m_adj[i][j];
  while (true) {
    f = 0;
    p.assign(graph.n, -1);
    vis.assign(graph.n, 0);
    find_path(graph.s);
    if (!vis[graph.t]) break;
    augment(graph.t, INF);
    if (f == 0) break;
    mf += f;
  }
  cout << "Fluxo total: " << mf << endl;
  return residual;
}
