#include <string>
#include <fstream>
#include <iostream>
#include<vector>

using namespace std;

class Aresta {
public:
	int u;
	int v;
	double peso;

	Aresta(){}

	Aresta(int u, int v, int peso){
		this->u = u;
		this->v = v;
		this->peso = peso;
	}

	bool operator < (const Aresta& aresta) const{
		return (this->peso < aresta.peso);
	}
};

class Graph{
public:
	int n;
	int m;
	vector<Aresta> arestas;

	Graph(){
	}

	void loadGrafo(string path);
	void printGraph();
};