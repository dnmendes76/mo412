#include <iostream>
#include <bellman_ford.h>
#include <djikstra.h>
#include <floyd_warshall.h>
#include <johnson.h>

int main() {
    Graph * graph = new Graph();
    graph->load_graph("toy_instance.txt");
    BellmanFord bf = BellmanFord(graph);
    bf.solve();
    bf.salve_soluction("bf.txt");

    Djikstra dj = Djikstra(graph);
    dj.solve();
    dj.salve_soluction("dj.txt");

    FloydWarshall fw = FloydWarshall(graph);
    fw.solve();
    fw.salve_soluction_all_pairs("fw.txt");

	Johnson js = Johnson(graph);
    js.solve();
    js.salve_soluction_all_pairs("js.txt");

    return 0;
}