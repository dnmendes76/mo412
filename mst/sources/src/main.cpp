#include "../inc/kruskal.h"
#include "../inc/prim.h"
#include "../inc/filter_kruskal.h"


int main(int argc, char const *argv[]){
    if (argc != 5) {
        printf("Informe 4 argumentos.\n");
        return 0;
    }

    Graph graph;
    graph.load_grafo(argv[3]);


    MST_Filter_Kruskal mst3(graph);
    Soluction sol0 = mst3.solve();
    cout << sol0.valor << endl;

    MST_Kruskal mst2(graph);
    Soluction sol1 = mst2.solve_without_heuristics();
    cout << sol1.valor << endl;

    Soluction sol2 = mst2.solve_with_heuristic_path_compression();
    cout << sol2.valor << endl;

    Soluction sol3 = mst2.solve_with_heuristic_union_by_rank();
    cout << sol3.valor << endl;

    Soluction sol4 = mst2.solve_with_both_heuristics();
    cout << sol4.valor << endl;

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
