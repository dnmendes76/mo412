#include "../inc/kruskal.h"
#include "../inc/union_find.h"

MST_Kruskal::MST_Kruskal(Graph graph){
	this->graph = graph;
}


Soluction MST_Kruskal::solve(){
	UnionFind set(graph.n);
	for(int i=0; i<graph.n; i++) 
		set.make_set(i);
	vector<Aresta> arestas;
	for(int i=0; i<graph.n; i++){
		for(int j=0; j<graph.adj[i].size(); j++){
			Aresta e = graph.adj[i][j];
			arestas.push_back(e);
		}
	}
	sort(arestas.begin(), arestas.end());

	Soluction soluction;
	for (int i=0; i<graph.m; i++) {
		Aresta e = arestas[i];
		if(set.find_set(e.u) != set.find_set(e.v)) {
			set.union_set(e.u, e.v);
			soluction.valor += e.peso;
			soluction.arestas.push_back(e);
		}
	}
	return soluction;
}