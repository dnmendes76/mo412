#ifndef SOLUCTION_H
#define SOLUCTION_H

#include "grafo.h"

class Soluction{
public:
	vector<Aresta> arestas;
	double valor;

	Soluction(){
		this->valor = 0.0;
	}
};

#endif
