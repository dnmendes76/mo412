#include "johnson.h"
#include "bellman_ford.h"
#include "djikstra.h"

Johnson::Johnson(Graph* graph) {
	this->graph = graph;
    this->distance_all_pairs = vector<vector<double>>(graph->n, vector<double>(graph->n));
    this->pi_all_pairs = vector<vector<int>>(graph->n, vector<int>(graph->n));
    
    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            distance_all_pairs[i][j] = graph->adjMatrix[i][j];
            pi_all_pairs[i][j] = -1;
        }
    }
}

Graph* Johnson::modify_graph() {
	Graph *graph_ = new Graph();
	int n = graph->n;
	graph_->n = n+1;
	graph_->adj.resize(n+1);
	graph_->adjMatrix = vector<vector<double>>(n+1, vector<double>(n+1));
	for (Edge e : graph->edges) {
		graph_->adjMatrix[e.u][e.v] = e.weight;
		graph_->adj[e.u].push_back(e);
		graph_->edges.push_back(e);
    }

    int s = n;
    for(int v=0; v<n; v++){
    	Edge e(s,v,0);
    	graph_->adjMatrix[s][v] = 0;
    	graph_->adj[s].push_back(e);
    	graph_->edges.push_back(e);
    }
    graph_->s = s;
    graph_->m = graph->m + n; 

	return graph_;
}

Graph* Johnson::update_graph(vector<double> distance) {
	Graph *graph_ = new Graph();
	int n = graph->n;
	graph_->n = n;
	graph_->adj.resize(n);
	graph_->adjMatrix = vector<vector<double>>(n, vector<double>(n));
	double peso;
	for (Edge e : graph->edges) {
		peso = e.weight + distance[e.u] - distance[e.v];
		e.weight = peso;
		graph_->adjMatrix[e.u][e.v] = e.weight;
		graph_->adj[e.u].push_back(e);
		graph_->edges.push_back(e);
    }
    return graph_;
}

void Johnson::solve() {
	Graph *graph_ = modify_graph();
	BellmanFord bf = BellmanFord(graph_);
	bf.solve();

	graph_ = update_graph(bf.distance);
	vector<double> aux = vector<double>(graph->n);

	for(int s=0; s<graph_->n; s++){
		graph_->s = s;
		Djikstra dk = Djikstra(graph_);
		dk.solve_heap_binary();
		pi_all_pairs[s] = dk.pi;
		for(int v=0; v<graph->n; v++){
			aux[v] = dk.distance[v] - bf.distance[s] + bf.distance[v];
		}
		distance_all_pairs[s] = aux;
    }
}
