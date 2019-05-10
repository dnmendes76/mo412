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
		return (this->peso - aresta.peso < 10e-9);
	}
};

class Graph{
public:
	int n;
	int m;
	vector<vector<Aresta>> adj;

	Graph(){
	}

	void load_grafo(string path);
	void print_grafo();
};