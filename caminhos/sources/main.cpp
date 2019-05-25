#include <iostream>
#include <graph.h>
#include <Bellman_Ford.h>

int main() {
    Graph * graph = new Graph();
    graph->load_graph("toy_instance.txt");
    Bellman_Ford bf = Bellman_Ford(graph);
    bf.solve();
    return 0;
}