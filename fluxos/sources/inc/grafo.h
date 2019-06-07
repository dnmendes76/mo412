#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Aresta {
public:
    int u;
    int v;
    double custo;

    Aresta() {}

    Aresta(int u, int v, int custo) {
        this->u = u;
        this->v = v;
        this->custo = custo;
    }

    bool operator<(const Aresta &aresta) const {
        return (this->custo < aresta.custo);
    }
};

class Graph {
public:
  int n;
  int m;
  int s;
  int t;

  vector<vector<int>> m_adj;

  Graph() {
  }

  void load_grafo(string path);

  void print_grafo();
};

#endif
