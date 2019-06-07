#include "../inc/grafo.h"
#include "../inc/edmons_karp.h"
#include "../inc/save.h"

int main(int argc, char const *argv[]){
  if (argc != 4) {
    printf("Informe 3 argumentos.\nEx.: ford-fulkerson input.txt output.txt");
    return 0;
  }

  Graph graph, soluction;
  graph.load_grafo(argv[2]);
  graph.print_grafo();

  Fluxo_Edmons_Karp ek(graph);
  soluction = ek.solve();

  Save salva_arquivo(soluction);
  salva_arquivo.save_soluction(argv[2], argv[3]);

  for (int i = 0; i < graph.n; i++) {
    printf("[%d]: ", i);
    for (int j = 0; j < graph.n; j++) {
      if (graph.m_adj[i][j]) cout << "(" << soluction.m_adj[j][i] << ") ";
      else cout << "(" << 0 << ") ";
    }
    cout << endl;
  }
  return 0;
}
