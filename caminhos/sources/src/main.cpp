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

    Djikstra dj = Djikstra(graph);
    dj.solve();

    FloydWarshall fw = FloydWarshall(graph);
    fw.solve();

    Johnson js = Johnson(graph);
    js.solve();

    return 0;
}