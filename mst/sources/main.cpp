#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kruskal.h"

const int TAM_PALAVRA = 112;

void escreve_arquivo(solucao_t grafo, FILE *saida) {
  int i;
  fprintf(saida, "%.2lf\n", grafo.sol);
  for (i = 0; i < (int)grafo.arestas.size(); i++)
    fprintf(saida, "%d %d %.2lf\n", grafo.arestas[i].u, grafo.arestas[i].v, grafo.arestas[i].peso);
}

int main(int argc, char *argv[]) {
  int estrutura;
  char algoritmo[TAM_PALAVRA];
  FILE *entrada, *saida;
  solucao_t ans;
  if (argc != 5) {
    printf("Informe 4 argumentos.\n");
    return 0;
  }
  strcpy(algoritmo, argv[1]);
  estrutura = atoi(argv[2]);
  entrada = fopen(argv[3], "r");
  saida = fopen(argv[4], "w+");
  if (strcmp(algoritmo, "kruskal") == 0) ans = kruskal(entrada, estrutura);
  escreve_arquivo(ans, saida);
  return 0;
}
