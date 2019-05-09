#include "../inc/kruskal.h"

MST_Kruskal::MST_Kruskal(Graph graph){
	this->graph = graph;
	parent.resize(graph.n);
	rank.resize(graph.n);
}

void MST_Kruskal::make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int MST_Kruskal::find_set(int i) {
    return (parent[i] == i) ? i : (parent[i] = find_set(parent[i]));
}

bool MST_Kruskal::same_set(int i, int j) {
    return find_set(i) == find_set(j);
}

void MST_Kruskal::union_set(int i, int j) {
    int x, y;
    if (!same_set(i, j)) {
        x = find_set(i);
        y = find_set(j);
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
}

Soluction MST_Kruskal::solve(){
	for(int i=0; i<graph.n; i++) 
		make_set(i);
	sort(graph.arestas.begin(), graph.arestas.end());

	Soluction soluction;
	for (int i=0; i<graph.m; i++) {
		Aresta e = graph.arestas[i];
		if(find_set(e.u) != find_set(e.v)) {
			union_set(e.u, e.v);
			soluction.valor += e.peso;
			soluction.arestas.push_back(e);
		}
	}
	return soluction;
}