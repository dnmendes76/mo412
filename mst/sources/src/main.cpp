#include "../inc/kruskal.h"
#include "../inc/prim.h"
#include "../inc/filter_kruskal.h"

void salve_soluction(Soluction soluction, string path) {
    cout << "Salvando Soluction..." << endl;
    ofstream file;
    file.open(path);
    file << soluction.valor << endl;
    Aresta e;
    for (int i=0; i<(int)soluction.arestas.size(); i++) {
        e = soluction.arestas[i];
        file << e.u << ' ' << e.v << ' ' << e.peso << endl;
    }
    cout << "Soluction salva com sucesso \\o/" << endl;
    file.close();
}

int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\nEx.: prim 0 input.txt output.txt");
        return 0;
    }
    Graph graph;
    graph.load_grafo(argv[3]);

    Soluction soluction;
    string alg[2] = {"kruskal", "prim"};
    int option = atoi(((string)argv[2]).c_str());

    if(alg[0].compare(argv[1]) == 0) {
        cout << argv[1] << '-' << option << endl;
        MST_Kruskal mst(graph);

        switch(option) {
            case 0:
                soluction = mst.solve_without_heuristics();
                //cout << soluction.valor << endl;
                break;
            case 1:
                soluction = mst.solve_with_heuristic_path_compression();
                break;
            case 2:
                soluction = mst.solve_with_heuristic_union_by_rank();
                break;
            case 4:
                soluction = mst.solve_with_both_heuristics();
                break;
            case 5:
                MST_Filter_Kruskal mst2(graph);
                soluction = mst2.solve();
                break;
        }

    } else if(alg[1].compare(argv[1]) == 0) {
        cout << argv[1] << '-' << option << endl;
        MST_Prim mst(graph);
        switch(option) {
            case 0:
                soluction = mst.solve_heap_vector(0);
                //cout << soluction.valor << endl;
                break;
            case 1:
                soluction = mst.solve_heap_binary(0);
                break;
            case 2:
                soluction = mst.solve_heap_fibonacci_use_insert(0);
                break;
            case 4:
                soluction = mst.solve_heap_fibonacci_use_decrease(0);
                break;
        }

    } else {
        cout << "Sorry! This algorithm not implemented yet :|" << endl;
        return 0;
    }

    salve_soluction(soluction, argv[4]);

    return 0;
}
