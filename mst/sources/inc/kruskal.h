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

	vector<int> parent;
	vector<int> rank;
	void make_set(int x);
	int find_set(int i);
	bool same_set(int i, int j);
	void union_set(int i, int j);

public:

	Graph graph;
	MST_Kruskal(Graph graph);

	Soluction solve();

};


