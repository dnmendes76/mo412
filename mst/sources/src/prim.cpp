#include "../inc/prim.h"
#include "../inc/heap_binary.h"

MST_Prim::MST_Prim(Graph graph){
	this->graph = graph;
	this->parent.resize(graph.n);
}

Soluction MST_Prim::obter_soluction() {
	Aresta e;
	Soluction soluction;
	for(int i=0; i<graph.n; i++){
		if(parent[i] != -1) {
			e.u = parent[i];
			e.v = i;
			e.peso = graph.adj[e.u][e.v].peso;
			soluction.arestas.push_back(e);
			soluction.valor += e.peso;
		}
	}
	return soluction;
}

Soluction MST_Prim::solve(int root) {
	HeapBinary heap(graph.n);
	vector<bool> visited;
	visited.resize(graph.n);
	Node temp;

	for(int i=0; i<graph.n; i++) {
		temp.indice = i; temp.valor = 100000.0;
		heap.valores[i] = temp;
		parent[i]= -1;
		visited[i] = false;
	} 

	temp.indice = root; temp.valor = 0.0;
	heap.valores[root] = temp;
	visited[root] = true;
	heap.build_heap(graph.n);

	Soluction soluction;
	while(heap.size > 0) {
		Node u = heap.extract_min();
		cout<< "u- " << u.indice << endl;
		vector<Aresta>::iterator e;
		for(e=graph.adj[u.indice].begin(); e!=graph.adj[u.indice].end(); e++) {
			cout<< " u - v  " << u.indice << '-' << (*e).v  << endl;

			if(!visited[(*e).v] && (*e).peso < heap.valores[(*e).v].valor) {
				cout<< " u - v  " << u.indice << '-' << (*e).v  << endl;
				parent[(*e).v] = u.indice;
				temp.indice = (*e).v; temp.valor = (*e).peso;
				heap.decrease_key((*e).v, temp); 
				for(int i = 0; i<heap.size; i++){
					cout<< " heap.i  " << heap.valores[i].indice << " heap.valor " << heap.valores[i].valor  << endl;
				}
			}
		}
		visited[u.indice] = true;
		
		if(parent[u.indice] != -1) {
			Aresta e;
			e.u = parent[u.indice]; e.v = u.indice; e.peso = graph.adj[e.u][e.v].peso;
			soluction.arestas.push_back(e);
			soluction.valor += e.peso;
		}
	}
	return obter_soluction();
}