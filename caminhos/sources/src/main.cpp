#include <iostream>
#include <bellman_ford.h>
#include <djikstra.h>
#include <floyd_warshall.h>
#include <johnson.h>

int main(int argc, char const *argv[]) {
	if (argc != 5) {
        printf("Informe 4 argumentos.\nEx.: djikstra 0 input.txt output.txt");
        return 0;
    }

    Graph * graph = new Graph();
    graph->load_graph(argv[3]);
    BellmanFord bf = BellmanFord(graph);
    bf.solve();
    bf.salve_soluction("testes/outputs/bf.txt");

    Djikstra dj = Djikstra(graph);
    dj.solve();
    dj.salve_soluction("testes/outputs/dj.txt");

    FloydWarshall fw = FloydWarshall(graph);
    fw.solve();
    fw.salve_soluction_all_pairs("testes/outputs/fw.txt");

	Johnson js = Johnson(graph);
    js.solve();
    js.salve_soluction_all_pairs("testes/outputs/js.txt");

    return 0;
}