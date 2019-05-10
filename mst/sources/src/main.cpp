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
    Soluction soluction = mst.solve(0);

    cout << soluction.valor << endl;

    graph.print_grafo();

/*
    HeapBinary h(20);
    h.valores[0] = 3;
    h.valores[1] = 0.5;
    h.valores[2] = 2;
    h.valores[3] = 5; 
    h.build_heap(4);
    h.heap_insert(3); 
    h.heap_insert(2);
    h.heap_insert(1); 
    h.heap_insert(4); 
    h.heap_insert(45); 
    cout << h.extract_min() << " "; 
    cout << h.extract_min() << " "; 
    h.decrease_key(2, 1); 
    cout << h.extract_min() <<endl; 
    cout << h.extract_min() <<endl; 

    */
    return 0;
}