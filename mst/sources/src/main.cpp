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
    Soluction soluction = mst.solve_heap_binary(0);

    cout << soluction.valor << endl;

    //graph.print_grafo();

    return 0;
}
