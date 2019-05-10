#include "../inc/kruskal.h"
#include "../inc/heap_binary.h"

int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\n");
        return 0;
    }

    Graph graph;
    graph.load_grafo(argv[3]);

    MST_Kruskal mst(graph);
    Soluction soluction = mst.solve();

    cout << soluction.valor << endl;

    graph.print_grafo();

    /*
    vector<double> valores;
    valores.push_back(0.5);
    valores.push_back(7.0);
    valores.push_back(2.0);
    valores.push_back(3.0);

    HeapBinary h(20); 
    h.build_heap(valores);
    h.heap_insert(3); 
    h.heap_insert(2);
    h.heap_insert(5); 
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