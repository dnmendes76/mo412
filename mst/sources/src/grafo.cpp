#include "../inc/grafo.h"

void Graph::load_grafo(string path){
	cout << "Lendo Arquivo" << endl;
	
	ifstream file;
	file.open(path, fstream::in);
	file >> n >> m;

	Aresta e;
	adj.resize(n);
	for(int i=0; i<m; i++){
		file >> e.u >> e.v >> e.peso;
		adj[e.u].push_back(e);
	}

	cout << "Arquivo Carregado" << endl;
	file.close();
}

void Graph::print_grafo(){
	for(int i=0; i<n; i++){
		for(int j=0; j<adj[i].size(); j++){
			Aresta e = adj[i][j];
			cout << '(' << e.u << ',' << e.v << ") - " << e.peso << endl;

		}
	}
}