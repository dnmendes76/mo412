#include <iostream>
#include <graph.h>
#include <bellman_ford.h>

int main() {
    Graph * graph = new Graph();
    graph->load_graph("toy_instance.txt");
    BellmanFord bf = BellmanFord(graph);
    bf.solve();
    return 0;
}