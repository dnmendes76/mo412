#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kruskal.h"

const int WORD_SIZE = 112;

void write_archive(solution_t graph, FILE *output_archive) {
  int i;
  fprintf(output_archive, "%.2lf\n", graph.sol);
  for (i = 0; i < (int) graph.edges.size(); i++)
    fprintf(output_archive, "%d %d %.2lf\n", graph.edges[i].u, graph.edges[i].v, graph.edges[i].weight);
}

int main(int argc, char *argv[]) {
  int structure;
  char algorithm[WORD_SIZE];
  FILE *input, *output;
  solution_t ans;

  if (argc != 5) {
    printf("Informe 4 argumentos.\n");
    return 0;
  }

  strcpy(algorithm, argv[1]);
  structure = atoi(argv[2]);
  input = fopen(argv[3], "r");
  output = fopen(argv[4], "w+");
  if (strcmp(algorithm, "kruskal") == 0) ans = kruskal(input, structure);
  write_archive(ans, output);
  return 0;
}
