#include "../inc/kruskal.h"
#include "../inc/prim.h"

int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\n");
        return 0;
    }

    Graph graph;
    graph.load_grafo(argv[3]);

    MST_Kruskal mst2(graph);
    Soluction sol1 = mst2.solve();

    cout << sol1.valor << endl;

    MST_Prim mst(graph);
    Soluction soluction1 = mst.solve_heap_vector(0);
    cout << soluction1.valor << endl;

    Soluction soluction2 = mst.solve_heap_binary(0);
    cout << soluction2.valor << endl;

    Soluction soluction3 = mst.solve_heap_fibonacci_use_insert(0);
    cout << soluction3.valor << endl;

    Soluction soluction4 = mst.solve_heap_fibonacci_use_decrease(0);
    cout << soluction4.valor << endl;


    //graph.print_grafo();

    return 0;
}
