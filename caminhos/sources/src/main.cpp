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

    BellmanFord is_valid = BellmanFord(graph);
    is_valid.solve();
    if(is_valid.has_negative_cycle){
        ofstream file;
        file.open(path_output);
        file << "Graph has negative cycle! :/" << endl;
        cout << "Graph has negative cycle! :/" << endl;
        file.close();
        exit(0);
    }

    if(alg[0].compare(argv[1]) == 0) { //bellman-ford
    	BellmanFord bf = BellmanFord(graph);
        if(option == 0){
            bf.solve();
        } else if (option == 1) {
            bf.solve_two();
        } else {
            cout << "Invalid Option!" << endl;
        }
        bf.salve_soluction(path_output);

    } else if(alg[1].compare(argv[1]) == 0) { //dijkstra
    	Dijkstra dj = Dijkstra(graph);
        if(option == 0) {
            dj.solve_vector();
        } else if (option == 1) {
            dj.solve_heap_binary();
        } else if (option == 2) {
            dj.solve_heap_fibonacci();
        } else {
            cout << "Invalid Option!" << endl;
        }
        dj.salve_soluction(path_output);

    } else if(alg[2].compare(argv[1]) == 0) { //floyd-warshall
    	FloydWarshall fw = FloydWarshall(graph);
        if(option == 0) {
            fw.solve();
            fw.salve_soluction_all_pairs(path_output);
        } else {
            cout << "Invalid Option!" << endl;
        }

    } else if (alg[3].compare(argv[1]) == 0) { // johnson
    	Johnson js = Johnson(graph);
        if(option == 0) {
            js.solve_dijkstra_vector();
        } else if (option == 1) {
            js.solve_dijkstra_heap_bin();
        } else if (option == 2) {
            js.solve_dijkstra_heap_fibo();
        } else {
            cout << "Invalid Option!" << endl;
        }
        js.salve_soluction_all_pairs(path_output);

    } else {
    	cout << "Sorry! This algorithm not implemented yet :|" << endl;
    }

    return 0;
}