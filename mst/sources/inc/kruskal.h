#include "grafo.h"
#include <algorithm>

using namespace std;

class Soluction{
public:
	vector<Aresta> arestas;
	double valor;

	Soluction(){
		this->valor = 0.0;
	}
};

class MST_Kruskal{
public:

	Graph graph;
	MST_Kruskal(Graph graph);

	Soluction solve();

};


