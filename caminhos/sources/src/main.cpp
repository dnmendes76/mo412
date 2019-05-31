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
    bf.solve_two();
    bf.salve_soluction("testes/outputs/bf2.txt");

    Djikstra dj = Djikstra(graph);
    dj.solve_heap_binary();
    dj.salve_soluction("testes/outputs/dj1.txt");

    dj.solve_heap_fibonacci();
    dj.salve_soluction("testes/outputs/dj2.txt");

    dj.solve_vector();
    dj.salve_soluction("testes/outputs/dj3.txt");

    FloydWarshall fw = FloydWarshall(graph);
    fw.solve();
    fw.salve_soluction_all_pairs("testes/outputs/fw.txt");

	Johnson js = Johnson(graph);
    js.solve_djikstra_vector();
    js.salve_soluction_all_pairs("testes/outputs/js.txt");

    js.solve_djikstra_heap_bin();
    js.salve_soluction_all_pairs("testes/outputs/js2.txt");

    js.solve_djikstra_heap_fibo();
    js.salve_soluction_all_pairs("testes/outputs/js3.txt");

    return 0;
}