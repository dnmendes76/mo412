#include "../inc/grafo.h"

void Graph::load_grafo(string path){
	cout << "Lendo Arquivo" << endl;
	
	ifstream file;
	file.open(path, fstream::in);
	file >> n >> m;

	Aresta e;
	for(int i=0; i<m; i++){
		file >> e.u >> e.v >> e.peso;
		arestas.push_back(e);
	}

	cout << "Arquivo Carregado" << endl;
	file.close();
}

void Graph::print_grafo(){
	for(int i=0; i<m; i++){
		Aresta e = arestas[i];
		cout << '(' << e.u << ',' << e.v << ") - " << e.peso << endl;
	}
}