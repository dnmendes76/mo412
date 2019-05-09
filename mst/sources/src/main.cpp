#include "../inc/kruskal.h"

int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\n");
        return 0;
    }

    Graph graph;
    graph.loadGrafo(argv[3]);

    MST_Kruskal mst(graph);
    Soluction soluction = mst.solve();

    cout << soluction.valor << endl;

    graph.printGraph();
    return 0;
}