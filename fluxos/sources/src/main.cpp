#include "../inc/grafo.h"
#include "../inc/edmons_karp.h"
#include "../inc/ford_fulkerson.h"
#include "../inc/save.h"

int main(int argc, char const *argv[]){
  if (argc != 4) {
    printf("Informe 3 argumentos.\nEx.: ford-fulkerson input.txt output.txt");
    return 0;
  }

  string alg[4] = {"ford-fulkerson", "edmonds-karp"};

  Graph graph, soluction;
  graph.load_grafo(argv[2]);
  //graph.print_grafo();

  if (alg[0].compare(argv[1]) == 0) { //Ford-Fulkerson
    Fluxo_Edmons_Karp fk(graph);
    soluction = fk.solve();
  } else if (alg[1].compare(argv[1]) == 0) { //Edmons-Karp
    Fluxo_Edmons_Karp ek(graph);
    soluction = ek.solve();
  } else {
    cout << "Opcao Invalida" << endl;
    return 0;
  }

  Save salva_arquivo(soluction);
  salva_arquivo.save_soluction(argv[2], argv[3]);

  return 0;
}
