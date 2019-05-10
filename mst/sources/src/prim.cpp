#include "../inc/prim.h"
#include "../inc/heap_binary.h"

MST_Prim::MST_Prim(Graph graph){
	this->graph = graph;
	this->parent.resize(graph.n);
}

Soluction MST_Prim::obter_soluction() {
	Aresta e;
	Soluction soluction;
	for(int i=1; i<graph.n; i++){
		e.u = parent[i];
		e.v = i;
		e.peso = graph.adj[e.u][e.v].peso;
		soluction.arestas.push_back(e);
		soluction.valor += e.peso;
	}
	return soluction;
}

Soluction MST_Prim::solve(int root) {
	HeapBinary heap(graph.n);
	vector<bool> visited;
	visited.resize(graph.n);

	for(int i=0; i<graph.n; i++) {
		heap.valores[i] = 1000000.02;
		parent[i]= -1;
		visited[i] = false;
	} 
	heap.valores[root] = 0;
	visited[root] = true;
	heap.build_heap(graph.n);

	Soluction soluction;
	while(heap.size > 0) {
		int u = heap.extract_min();
		for(vector<Aresta>::iterator e=graph.adj[u].begin(); e!=graph.adj[u].end(); e++) {
			if(!visited[(*e).v] && (*e).peso < heap.valores[(*e).v]) {
				parent[(*e).v] = u;
				heap.decrease_key((*e).v, (*e).peso); // to do -- corrigir para salvar a tupla (v, peso) na heap
			}
		}
		visited[u] = true;
	}
	return obter_soluction();
}