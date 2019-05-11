//#include "../inc/kruskal.h"
#include "../inc/prim.h"

int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\n");
        return 0;
    }

    Graph graph;
    graph.load_grafo(argv[3]);

    MST_Prim mst(graph);
    Soluction soluction = mst.solve_heap_binary(9);

    cout << soluction.valor << endl;

    //graph.print_grafo();

    return 0;
}
