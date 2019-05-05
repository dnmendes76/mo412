#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kruskal.h"

const int TAM_PALAVRA = 112;

int main(int argc, char *argv[]) {
  int estrutura;
  char algoritmo[TAM_PALAVRA];
  FILE *entrada, *saida;
  strcpy(algoritmo, argv[1]);
  estrutura = atoi(argv[2]);
  entrada = fopen(argv[3], "r");
  saida = fopen(argv[4], "w+");
  return 0;
}
