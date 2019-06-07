#include "../inc/save.h"
#include "../inc/grafo.h"

Save::Save(Graph graph) {
  this->graph = graph;
}

void Save::save_soluction(string path_in, string path_out) {
  int n, m, s, t;

  ifstream file_in;
  file_in.open(path_in, fstream::in);
  ofstream file_out;
  file_out.open(path_out);

  file_in >> n >> m >> s >> t;
  Aresta e, aux;
  for (int i = 0; i < m; i++) {
    file_in >> e.u >> e.v >> e.custo;
    file_out << e.u << ' ' << e.v << ' ' << graph.m_adj[e.v][e.u] << endl;;
  }

  file_in.close();
  file_out.close();
}
