#include <iostream>
#include <bellman_ford.h>
#include <dijkstra.h>
#include <floyd_warshall.h>
#include <johnson.h>

int main(int argc, char const *argv[]) {
	if (argc != 5) {
        printf("Informe 4 argumentos.\nEx.: dijkstra 0 input.txt output.txt");
        return 0;
    }

    Graph * graph = new Graph();
    graph->load_graph(argv[3]);
    string alg[4] = {"bellman-ford", "dijkstra", "floyd-warshall", "johnson"};
    int option = atoi(((string)argv[2]).c_str());
    string path_output = argv[4];

    if(alg[0].compare(argv[1]) == 0) { //bellman-ford
    	BellmanFord bf = BellmanFord(graph);

    } else if(alg[1].compare(argv[1]) == 0) { //dijkstra
    	Dijkstra dj = Dijkstra(graph);

    } else if(alg[2].compare(argv[1]) == 0) { //floyd-warshall
    	FloydWarshall fw = FloydWarshall(graph);

    } else if (alg[3].compare(argv[1]) == 0) { // johnson
    	Johnson js = Johnson(graph);

    } else {
    	cout << "Sorry! This algorithm not implemented yet :|" << endl;
    }



    BellmanFord bf = BellmanFord(graph);
    bf.solve();
    bf.salve_soluction("testes/outputs/bf.txt");
    bf.solve_two();
    bf.salve_soluction("testes/outputs/bf2.txt");

    Dijkstra dj = Dijkstra(graph);
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
    js.solve_dijkstra_vector();
    js.salve_soluction_all_pairs("testes/outputs/js.txt");

    js.solve_dijkstra_heap_bin();
    js.salve_soluction_all_pairs("testes/outputs/js2.txt");

    js.solve_dijkstra_heap_fibo();
    js.salve_soluction_all_pairs("testes/outputs/js3.txt");


    return 0;
}